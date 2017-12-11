#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <entities/WorldObjectInterface.h>
#include "collision_result_t.h"

class CollisionModelInterface {
 public:
  virtual collision_result_t check(WorldObjectInterface *a, WorldObjectInterface *b) = 0;
};