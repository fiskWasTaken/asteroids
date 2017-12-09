//
// Created by fisk on 17/10/17.
//

#ifndef ASTEROIDS_WORLDOBJECTINTERFACE_H
#define ASTEROIDS_WORLDOBJECTINTERFACE_H

#include <SFML/Window.hpp>
#include "WorldObjectClass.h"

class WorldObjectInterface {
 public:
  std::vector<sf::Vector2f> points;
  sf::Vector2f pos;
  sf::Vector2f vel;
  sf::Vector2f acc;
  float rot;

  const std::vector<sf::Vector2f> &getPoints() const {
    return points;
  }

  virtual WorldObjectClass getClass() {
    return WorldObjectClass::NONE;
  }

  virtual void onCollision(WorldObjectInterface *other) {}
};

#endif //ASTEROIDS_WORLDOBJECTINTERFACE_H
