#pragma once

#include <input/ControllerListenerInterface.h>
#include <renderer/WorldRenderer.h>
#include <Asteroids.h>
#include "SceneInterface.h"

class StressTestScene : public SceneInterface, public ControllerListenerInterface {
  Asteroids *game;
  World world;

  WorldRenderer worldRenderer;
 public:
  explicit StressTestScene(Asteroids *game) : world(game, 640, 480) {
    this->game = game;
  }

  void render(WindowRendererInterface *renderer) override;
  void onAction(InputAction action, bool once) override;
  void onVisible() override;
  void main() override;

  ~StressTestScene() override {
    game->getControllers().getFirst()->setDelegate(nullptr);
  }
};


