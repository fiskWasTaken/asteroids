#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <optional>
#include <entities/IActor.h>
#include "collision_result_t.h"

class CollisionModelInterface {
 public:
  virtual collision_result_t check(IActor *a, IActor *b) = 0;
};