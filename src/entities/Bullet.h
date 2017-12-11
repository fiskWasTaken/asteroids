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

  explicit Bullet(WorldInterface *world) : AbstractWorldObject(world) {
    points.emplace_back(2, 1);
    points.emplace_back(0, 0);
    points.emplace_back(0, 2);
    origin = sf::Vector2f(1, 1);
  }

  bool isRecyclable() override {
    return lifetime <= 0;
  }

  void update() override {
    pos += vel;
    lifetime--;
  };

  void setLifetime(int lifetime);

  void renderTo(sf::RenderWindow *renderWindow) override;

};

#endif //ASTEROIDS_BULLET_H
