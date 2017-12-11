#pragma once

#include <world/WorldInterface.h>
#include "level_t.h"

/**
 * Places entities described by level_t into the world
 */
class LevelLoader {
 public:
  void load(WorldInterface *world, level_t level);
};


