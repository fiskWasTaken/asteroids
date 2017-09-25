//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H

#include "WorldObject.h"

class Bullet : WorldObject {
  int lifetime = 100;

 public:
  static const WorldObjectClass OBJECT_CLASS = WorldObjectClass::BULLET;

  Bullet() {

  }

  void update() {
    lifetime--;
  };
};

#endif //ASTEROIDS_BULLET_H
