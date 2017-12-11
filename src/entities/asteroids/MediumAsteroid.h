//
// Created by fisk on 11/12/17.
//

#ifndef ASTEROIDS_MEDIUMASTEROID_H
#define ASTEROIDS_MEDIUMASTEROID_H

#include "AsteroidBase.h"
class MediumAsteroid : public AsteroidBase {
 public:
  explicit MediumAsteroid(WorldInterface *world) : AsteroidBase(world) {
      points.emplace_back(15, 0);
      points.emplace_back(30, 7.5f);
      points.emplace_back(30, 21.5f);
      points.emplace_back(15, 30);
      points.emplace_back(0, 21.5f);
      points.emplace_back(0, 7.5f);
      origin = sf::Vector2f(15, 15);
  }

  inline int getMaxHealth() {
    return 30;
  }

  void onDestroyed() override;
};

#endif //ASTEROIDS_MEDIUMASTEROID_H
