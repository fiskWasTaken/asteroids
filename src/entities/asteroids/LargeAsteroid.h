//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_ASTEROID_H
#define ASTEROIDS_ASTEROID_H

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
  }

  inline int getMaxHealth() {
    return 50;
  }

  void onDestroyed() override;
};

#endif //ASTEROIDS_ASTEROID_H
