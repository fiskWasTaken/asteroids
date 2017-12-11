//
// Created by fisk on 11/12/17.
//

#ifndef ASTEROIDS_SMALLASTEROID_H
#define ASTEROIDS_SMALLASTEROID_H

#include "AsteroidBase.h"
class SmallAsteroid : public AsteroidBase {
 public:
  explicit SmallAsteroid(WorldInterface *world) : AsteroidBase(world) {
      points.emplace_back(7.5f, 0);
      points.emplace_back(15, 3.75f);
      points.emplace_back(15, 11.25f);
      points.emplace_back(7.5f, 15);
      points.emplace_back(0, 11.25f);
      points.emplace_back(0, 3.75f);
      origin = sf::Vector2f(7.5f, 7.5f);
  }

  inline int getMaxHealth() {
    return 10;
  }

  void onDestroyed() override;
};

#endif //ASTEROIDS_SMALLASTEROID_H
