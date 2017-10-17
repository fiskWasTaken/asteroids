//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

#include "AbstractWorldObject.h"

class Asteroid : public AbstractWorldObject {
 private:
  int health = 100;
  int size = 0;

 public:
  static const WorldObjectClass OBJECT_CLASS = WorldObjectClass::ASTEROID;

  explicit Asteroid(World *world) : AbstractWorldObject(world) {}

  inline int getHealth() {
    return health;
  }

  inline void setSize(int size) {
    this->size = size;
  }

  inline void takeDamage(int damage) {
    health -= damage;

    if (health < 0)
      health = 0;
  }
  void update() override;
  void onCollision(AbstractWorldObject *other) override;
  void onDestroyed();
  bool isRecyclable() override;

  sf::Drawable *getDrawable() override;
};

#endif //ASTEROIDS_ASTEROID_H
