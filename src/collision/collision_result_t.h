#pragma once

#include <SFML/System.hpp>

/**
 * mtv -- the minimum translation vector -- is the smallest translation
 * needed to stop two actors from being in collision
 */
struct collision_result_t {
  bool isCollision = false;
  sf::Vector2f mtv;
};