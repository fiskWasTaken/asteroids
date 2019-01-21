#include <entities/Asteroid.h>
#include "WaveGenerator.h"

void WaveGenerator::placeRandomly(WorldInterface *world, AbstractWorldObject *object) {
  object->pos.x = this->randomizer.rnd(0, INT_MAX) % int(world->getWidth());
  object->pos.y = this->randomizer.rnd(0, INT_MAX) % int(world->getHeight());
  object->vel.x = -0.5 + this->randomizer.rnd(0, INT_MAX) % 2;
  object->vel.y = -0.5 + this->randomizer.rnd(0, INT_MAX) % 2;
  world->push(object);
}

void WaveGenerator::generate(WorldInterface *world, int level) {
  int baseCount = 4 + level;

  for (int i = 0; i < baseCount; i++) {
    this->placeRandomly(world, new Asteroid(world, 50));
  }
}
