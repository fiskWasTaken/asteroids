#pragma once

#include <Asteroids.h>
#include "SceneInterface.h"

class GameOverScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;
  ControllerInterface *controller;

 public:
  void render(RendererInterface *renderer) override;
  void handleEvents() override;
  void onVisible() override;
  void onDestroy() override;

  explicit GameOverScene(Asteroids *game) {
    this->game = game;
    this->controller = game->getDefaultController();
  }

  void onAction(InputAction action) override;
};