#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <entities/WorldObjectInterface.h>

struct collisionResult {
  bool isCollision = false;
  sf::Vector2f mtv;
};

class CollisionModelInterface {
 public:
  virtual collisionResult check(WorldObjectInterface *a, WorldObjectInterface *b) = 0;
};