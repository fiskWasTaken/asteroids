#pragma once

#include <Asteroids.h>
#include "SceneInterface.h"

class GameOverScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;
  ControllerInterface *controller;

 public:
  void render(WindowRendererInterface *renderer) override;
  void handleEvents() override;
  void onVisible() override;

  ~GameOverScene() override {
    delete controller;
  }

  explicit GameOverScene(Asteroids *game) {
    this->game = game;
    this->controller = game->getDefaultJoystickController();
  }

  void onAction(InputAction action) override;
};