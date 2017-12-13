#pragma once

#include <Asteroids.h>
#include <renderer/WorldRenderer.h>
#include "SceneInterface.h"
class MainMenuScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;
  ControllerInterface *controller;
  World *world;

  WorldRenderer worldRenderer;

  std::vector<int> menuOptions;
 public:
  explicit MainMenuScene(Asteroids *game) {
    this->game = game;
    controller = game->getDefaultJoystickController();
    world = new World(game, 640, 480);
  }
  void render(WindowRendererInterface *renderer) override;
  void handleEvents() override;
  void onAction(InputAction action) override;
  void onVisible() override;
  void main() override;

  ~MainMenuScene() override {
    delete controller;
    delete world;
  }
};
