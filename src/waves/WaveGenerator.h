#pragma once

#include <world/WorldInterface.h>
#include <particles/Randomizer.h>
#include <entities/Asteroid.h>
#include <entities/AIShip.h>

class WaveGenerator
{
private:
  void placeRandomly(WorldInterface *world, Actor *object)
  {
    object->pos.x = rand.rnd(0, INT32_MAX) % int(world->getWidth());
    object->pos.y = rand.rnd(0, INT32_MAX) % int(world->getHeight());
    object->vel.x = -0.5 + rand.rnd(0, INT32_MAX) % 2;
    object->vel.y = -0.5 + rand.rnd(0, INT32_MAX) % 2;
    world->push(object);
  }

  Randomizer<int> rand;

public:
  void generate(WorldInterface *world, int level)
  {
    int baseCount = 4 + level;

    for (int i = 0; i < baseCount; i++)
    {
      this->placeRandomly(world, new Asteroid(world, 50));
    }
    
    auto aiShip = new AIShip(world);
    aiShip->color = sf::Color(160, 32, 32, 255);
    this->placeRandomly(world, aiShip);
  }
};
