#pragma once

#include <entities/Actor.h>
#include <entities/Bullet.h>
#include <utility/shape.h>
#include <SFML/Graphics/ConvexShape.hpp>
#include "TemporaryParticle.h"
#include <utility/drawing.h>

class Asteroid : public Actor
{
private:
  float size;
  const sf::Color outlineColor = sf::Color(127, 127, 127);
  const sf::Color fillColor = sf::Color(255, 255, 255, 25);
  int health = 100;
  float rotSpeed = 0.1f;
  sf::ConvexShape shape;

public:
  explicit Asteroid(WorldInterface *world, float size) : Actor(world)
  {
    this->size = size;
    rotSpeed = (-5 + float(random() % 10)) / 10;

    auto edges = 5 + size / 20;
    points = shape::generateShape(static_cast<unsigned long>(edges), size);
    origin = sf::Vector2f(size / 2, size / 2);
    health = this->getMaxHealth();

    shape.setPointCount(points.size());

    for (size_t i = 0; i < points.size(); i++)
    {
      shape.setPoint(i, points[i]);
    }

    shape.setFillColor(fillColor);
    shape.setOutlineColor(outlineColor);
    shape.setOutlineThickness(1.0F);
    shape.setOrigin(origin.x, origin.y);
  }

  std::string getClass() override
  {
    return "asteroid";
  }

  bool isDestroyed() { return health <= 0; }
  void onDestroyed()
  {
    if (size > 13)
    {
      auto ast1 = new Asteroid(world, size / 2);
      ast1->pos.x = pos.x - size / 4;
      ast1->pos.y = pos.y;
      ast1->vel = vector::len(vector::rot(vel, vector::rot(vel) + 45), vector::len(vel) * 1.3f);

      world->push(ast1);

      auto ast2 = new Asteroid(world, size / 2);
      ast2->pos.x = pos.x + size / 4;
      ast2->pos.y = pos.y;
      ast2->vel = vector::len(vector::rot(vel, vector::rot(vel) - 45), vector::len(vel) * 1.3f);

      world->push(ast2);
    }

    auto explosion = new ParticleSystem(128, 128);
    explosion->setColor(sf::Color(255, 255, 255));
    explosion->setParticleSpeed(20);
    explosion->fuel(25);
    explosion->setDissolve(true);
    explosion->setDissolutionRate(10);
    explosion->setShape(Shape::CIRCLE);
    auto emitter = new TemporaryParticle(world, explosion);
    emitter->pos.x = pos.x;
    emitter->pos.y = pos.y;
    world->push(emitter);
  }

  int getMaxHealth() { return static_cast<int>(size); }
  int getScoreValue() { return static_cast<int>(size / 10); }
  int getHealth() { return health; }

  void onCollision(Actor *other)
  {
    auto klass = other->getClass();

    if (klass == "bullet")
    {
      onBulletHit(dynamic_cast<Bullet *>(other));
    }

    if (klass == "asteroid")
    {
      onAsteroidHit(dynamic_cast<Asteroid *>(other));
    }

    if (klass == "ship")
    {
      onShipHit(dynamic_cast<Ship *>(other));
    }
  }

  void renderAt(sf::RenderWindow *w, sf::Vector2f vec)
  {
    shape.setPosition(vec);
    shape.setRotation(rot);

    w->draw(shape);

    if (health < getMaxHealth())
    {
      progress_bar_t progress;
      progress.pos = sf::Vector2f(vec.x, vec.y + 40);
      progress.origin = sf::Vector2f(int(origin.x), 20);
      progress.progress = getHealth();
      progress.maxProgress = getMaxHealth();
      progress.fillColor = sf::Color::Red;

      drawing::drawProgressBar(
          w,
          progress);
    }
  }

  void renderTo(sf::RenderWindow *w)
  {
    // todo: lmao
    renderAt(w, pos);
    renderAt(w, sf::Vector2f{pos.x, pos.y + 480});
    renderAt(w, sf::Vector2f{pos.x + 640, pos.y});
    renderAt(w, sf::Vector2f{pos.x - 640, pos.y});
    renderAt(w, sf::Vector2f{pos.x + 640, pos.y + 480});
    renderAt(w, sf::Vector2f{pos.x - 640, pos.y + 480});
    renderAt(w, sf::Vector2f{pos.x + 640, pos.y - 480});
    renderAt(w, sf::Vector2f{pos.x - 640, pos.y - 480});
  }

  void update()
  {
    this->pos += vel;
    this->rot += rotSpeed;
  }

  void onBulletHit(Bullet *bullet)
  {
    // take damage
    takeDamage(10);
    vel.x += bullet->vel.x / 30;
    vel.y += bullet->vel.y / 30;
    bullet->setLifetime(0);

    if (isDestroyed())
    {
      auto session = bullet->getOwner();

      if (session != nullptr)
      {
        session->score += getScoreValue();
      }
    }

    auto ricochet = new ParticleSystem(128, 128);
    ricochet->setColor(bullet->color);
    ricochet->setParticleSpeed(20);
    ricochet->fuel(10);
    ricochet->setDissolve(true);
    ricochet->setDissolutionRate(10);
    ricochet->setShape(Shape::CIRCLE);
    auto emitter = new TemporaryParticle(world, ricochet);
    emitter->pos.x = bullet->pos.x;
    emitter->pos.y = bullet->pos.y;
    world->push(emitter);
  }

  void onAsteroidHit(Asteroid *other)
  {
    // bounce
    auto diff = vel - other->vel;
    diff.x /= 1.05;
    diff.y /= 1.05;

    vel -= diff;
    other->vel += diff;

    auto rotDiff = rotSpeed - other->rotSpeed;
    rotDiff /= 10.0;

    rotSpeed -= rotDiff;
    other->rotSpeed += rotDiff;
  }

  void onShipHit(Ship *other)
  {
    if (!other->isOnInvincibilityCooldown())
    {
      other->onDestroyed();
    }
  }

  void takeDamage(int damage)
  {
    // guards against triggering onDestroyed() multiple times if hit again before entity recycle
    if (health < 1)
      return;

    health -= damage;

    if (health <= 0)
      this->onDestroyed();
  }

  bool isRecyclable()
  {
    return isDestroyed();
  }
};
