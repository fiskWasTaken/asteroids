//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H

#include "AbstractWorldObject.h"

class Bullet : public AbstractWorldObject {
  int lifetime = 100;

 public:
  static const WorldObjectClass OBJECT_CLASS = WorldObjectClass::BULLET;

  sf::Drawable *getDrawable() override;

  explicit Bullet(World *world) : AbstractWorldObject(world) {}

  bool isRecyclable() override {
    return lifetime < 0;
  }

  void update() override {
    pos += vel;
    lifetime--;
  };


};

#endif //ASTEROIDS_BULLET_H
