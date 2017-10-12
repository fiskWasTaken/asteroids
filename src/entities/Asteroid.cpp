//
// Created by fisk on 21/09/17.
//

#include "Asteroid.h"

void Asteroid::update(World *world) {
  this->pos += vel;
  this->rot += 0.1F;
}

void Asteroid::onCollision(WorldObject *other) {
  if (other->OBJECT_CLASS == WorldObjectClass::ASTEROID) {
    // todo
  }
}
bool Asteroid::isRecyclable() {
  return health < 0;
}
