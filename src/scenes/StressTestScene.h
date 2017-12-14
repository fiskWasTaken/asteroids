#pragma once

#include <input/ControllerListenerInterface.h>
#include <renderer/WorldRenderer.h>
#include <Asteroids.h>
#include "SceneInterface.h"

class StressTestScene : public SceneInterface, public ControllerListenerInterface {
  Asteroids *game;
  World *world;

  WorldRenderer worldRenderer;
 public:
  explicit StressTestScene(Asteroids *game) {
    this->game = game;
    world = new World(game, 640, 480);
  }

  void render(WindowRendererInterface *renderer) override;
  void onAction(InputAction action, bool once) override;
  void onVisible() override;
  void main() override;

  ~StressTestScene() override {
    game->getControllers().getFirst()->setDelegate(nullptr);
    delete world;
  }
};


