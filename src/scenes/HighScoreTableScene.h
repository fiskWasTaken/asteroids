#pragma once

#include <Asteroids.h>
#include "SceneInterface.h"
class HighScoreTableScene : public SceneInterface {
 private:
 private:
  Asteroids *game;
  ControllerInterface *controller;

 public:
  explicit HighScoreTableScene(Asteroids *game) {
    this->game = game;
    this->controller = game->getDefaultJoystickController();
  }
  void render(WindowRendererInterface *renderer) override;
  void handleEvents() override;
  void onVisible() override;
};
