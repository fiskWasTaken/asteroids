#include <entities/asteroids/SmallAsteroid.h>
#include <entities/asteroids/MediumAsteroid.h>
#include <entities/asteroids/LargeAsteroid.h>
#include "LevelLoader.h"

void placeRandomly(WorldInterface *world, AbstractWorldObject *object) {
  object->pos.x = rand() % int(world->getWidth());
  object->pos.y = rand() % int(world->getHeight());
  object->vel.x = rand() % 2;
  object->vel.y = rand() % 2;
  world->pushObject(object);
}

void LevelLoader::load(WorldInterface *world, level_t level) {
  for (int i = 0; i < level.small_asteroid_count; i++) {
    placeRandomly(world, new SmallAsteroid(world));
  }

  for (int i = 0; i < level.medium_asteroid_count; i++) {
    placeRandomly(world, new MediumAsteroid(world));
  }

  for (int i = 0; i < level.large_asteroid_count; i++) {
    placeRandomly(world, new LargeAsteroid(world));
  }
}
