#pragma once

#include <input/ControllerListenerInterface.h>
#include <renderer/WorldRenderer.h>
#include <Asteroids.h>
#include "SceneInterface.h"

class StressTestScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;
  World world;
  WorldRenderer worldRenderer;

 public:
  explicit StressTestScene(Asteroids *game);

  void render(WindowRendererInterface *renderer) override;
  void onAction(InputAction action, bool once) override;
  void onVisible() override;
  void main() override;

  ~StressTestScene() override;
};


