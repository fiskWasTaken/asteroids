#pragma once

#include "entities/AbstractWorldObject.h"
#include "AsteroidBase.h"

class LargeAsteroid : public AsteroidBase {
 public:
  explicit LargeAsteroid(WorldInterface *world) : AsteroidBase(world) {
    points.emplace_back(25, 0);
    points.emplace_back(50, 12.5f);
    points.emplace_back(50, 37.5f);
    points.emplace_back(25, 50);
    points.emplace_back(0, 37.5f);
    points.emplace_back(0, 12.5f);
    origin = sf::Vector2f(25, 25);
    this->health = this->getMaxHealth();
  }

  inline int getMaxHealth() override {
    return 60;
  }

  void onDestroyed() override;
};