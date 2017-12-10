//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H

#include "AbstractWorldObject.h"

class Bullet : public AbstractWorldObject {
  int lifetime = 100;

 public:
  WorldObjectClass getClass() override {
    return WorldObjectClass::BULLET;
  }

  sf::Drawable *getDrawable() override;

  explicit Bullet(WorldInterface *world) : AbstractWorldObject(world) {
    points.push_back(sf::Vector2f(2, 1));
    points.push_back(sf::Vector2f(0, 0));
    points.push_back(sf::Vector2f(0, 2));
  }

  bool isRecyclable() override {
    return lifetime < 0;
  }

  void update() override {
    pos += vel;
    lifetime--;
  };

};

#endif //ASTEROIDS_BULLET_H
