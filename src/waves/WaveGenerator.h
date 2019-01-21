#pragma once

#include <world/WorldInterface.h>
#include <particles/Randomizer.h>

class WaveGenerator {
 private:
  void placeRandomly(WorldInterface *world, AbstractWorldObject *object);
  Randomizer randomizer;
 public:
  void generate(WorldInterface *world, int level);
};


