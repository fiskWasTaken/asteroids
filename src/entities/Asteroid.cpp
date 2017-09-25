//
// Created by fisk on 21/09/17.
//

#include "Asteroid.h"

void Asteroid::update() {
  this->pos += vel;
}

void Asteroid::onCollision(WorldObject other) {
  if (other.OBJECT_CLASS == WorldObjectClass::ASTEROID) {
    // todo
  }
}
