//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include "WorldObject.h"

class Asteroid : public WorldObject {
 private:
  int health;

 public:
  static const WorldObjectClass OBJECT_CLASS = WorldObjectClass::ASTEROID;

  inline int getHealth() {
    return health;
  }

  inline void takeDamage(int damage) {
    health -= damage;

    if (health < 0)
      health = 0;
  }
  void update() override;
  void onCollision(WorldObject other) override;
};

#endif //ASTEROIDS_ASTEROID_H
