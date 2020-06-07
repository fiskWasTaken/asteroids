#pragma once

#include <algorithm>
#include <set>
#include <collision/SATCollisionModel.h>
#include <collision/CollisionModelInterface.h>
#include <entities/Actor.h>
#include "IGame.h"
#include "WorldInterface.h"

class World : public WorldInterface
{
private:
  std::vector<Actor *> actors;
  double w;
  double h;
  SATCollisionModel collisionModel;
  IGame *game;

public:
  World(IGame *game, double w, double h)
  {
    this->game = game;
    this->w = w;
    this->h = h;
    this->collisionModel = SATCollisionModel();
    actors.reserve(2048);
  }

  ~World()
  {
    for (auto actor : actors)
    {
      delete actor;
    }
  }

  void update()
  {
    for (auto actor : actors)
    {
      wrapObject(actor);
      actor->update();
    }

    auto size = actors.size();

    for (int a = 0; a < size; a++)
    {
      if (actors[a]->points.empty())
      {
        continue;
      }

      for (int b = a + 1; b < size; b++)
      {
        if (actors[b]->points.empty())
        {
          continue;
        }

        auto result = collisionModel.check(actors[a], actors[b]);

        if (result.isCollision)
        {
          actors[a]->onCollision(actors[b]);
          actors[b]->onCollision(actors[a]);

          // repel objects from each other (should be object trait?
          auto offset = sf::Vector2f(result.mtv.x / 100, result.mtv.y / 100);

          actors[a]->pos -= offset;
          actors[b]->pos += offset;
        }
      }
    }

    recycle();
  }

  double getWidth() const override { return w; }
  double getHeight() const override { return h; }

  inline void wrapObject(IActor *actor) override
  {
    auto pos = &actor->pos;

    if (pos->x < 0)
      pos->x += w;
    else if (pos->x > w)
      pos->x -= w;

    if (pos->y < 0)
      pos->y += h;
    else if (pos->y > h)
      pos->y -= h;
  };

  /**
   * return a list of offsets for an actor
   * this is because we wrap entities around the world,
   * so we need to consider the collision and sprite for
   * the actor as it exists when it wraps around the world edges
   */
  std::vector<sf::Vector2f> positions(IActor *actor)
  {
    std::vector<sf::Vector2f> out;
    auto pos = actor->pos;
    auto points = &actor->points;

    // todo: VERY naive
    out.push_back(pos);
    pos.x += w;
    out.push_back(pos);
    pos.y += h;
    out.push_back(pos);
    pos.x -= w;
    out.push_back(pos);

    return out;
  }

  void contain(IActor *actor)
  {
    auto pos = &actor->pos;
    auto vel = &actor->vel;

    if (pos->x < 0)
    {
      pos->x = 0;
      vel->x = -vel->x;
    }
    else if (pos->x > w)
    {
      pos->x = w;
      vel->x = -vel->x;
    }

    if (pos->y < 0)
    {
      pos->y = 0;
      vel->y = -vel->y;
    }
    else if (pos->y > h)
    {
      pos->y = h;
      vel->y = -vel->y;
    }
  }

  bool push(Actor *actor) override
  {
    actors.push_back(actor);
    return true;
  }

  bool pop(Actor *actor)
  {
    actors.erase(std::remove(actors.begin(), actors.end(), actor), actors.end());
    return true;
  }

  const std::vector<Actor *> &getObjects() const { return actors; }

  IGame *getGame() override { return game; }

  // Recycles objects that are ready to be removed from the game world.
  void recycle()
  {
    auto it = actors.begin();

    while (it != actors.end())
    {
      if ((*it)->isRecyclable())
      {
        auto ref = *it;
        it = actors.erase(it);
        delete (ref);
      }
      else
      {
        ++it;
      }
    }
  }

  void clear() { actors.clear(); }

  std::vector<Actor*> getActors()
  {
    return actors;
  }
};