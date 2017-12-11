#pragma once

#include <SFML/System.hpp>

struct collision_result_t {
  bool isCollision = false;
  sf::Vector2f mtv;
};