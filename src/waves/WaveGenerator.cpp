#include <entities/Asteroid.h>
#include "WaveGenerator.h"

void placeRandomly(WorldInterface *world, AbstractWorldObject *object) {
  object->pos.x = rand() % int(world->getWidth());
  object->pos.y = rand() % int(world->getHeight());
  object->vel.x = -0.5 + rand() % 2;
  object->vel.y = -0.5 + rand() % 2;
  world->pushObject(object);
}

void WaveGenerator::generate(WorldInterface *world, int level) {
  int baseCount = 4 + level;

  for (int i = 0; i < baseCount; i++) {
    placeRandomly(world, new Asteroid(world, 50));
  }
}
