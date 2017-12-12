#pragma once

#include <world/World.h>
#include "WindowRendererInterface.h"

class WorldRenderer {
 private:
  sf::Time lastFrameTime;
  sf::Clock clock;

 public:
  void drawCollisionOffsets(WindowRendererInterface *renderer, World *world);
  void drawBg(WindowRendererInterface *renderer, World *world);
  void drawWorld(WindowRendererInterface *renderer, World *world);
  void drawTimings(WindowRendererInterface *renderer);
};