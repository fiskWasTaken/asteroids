#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "WorldObjectClass.h"

class WorldObjectInterface {
 public:
  std::vector<sf::Vector2f> points;
  sf::Vector2f origin;

  sf::Vector2f pos;
  sf::Vector2f vel;
  sf::Vector2f acc;
  float rot{};

  virtual WorldObjectClass getClass() {
    return WorldObjectClass::NONE;
  }

  /**
   * Invoked when this object is colliding with another object
   * This will be triggered on each frame in which there is a collision
   *
   * @param other the other object this object is colliding with
   */
  virtual void onCollision(WorldObjectInterface *other) {}

  virtual void renderTo(sf::RenderWindow *renderWindow) = 0;
};
