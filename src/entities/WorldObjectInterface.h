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
  float rot;

  virtual WorldObjectClass getClass() {
    return WorldObjectClass::NONE;
  }

  virtual void onCollision(WorldObjectInterface *other) {}

  virtual void renderTo(sf::RenderWindow *renderWindow) = 0;
};
