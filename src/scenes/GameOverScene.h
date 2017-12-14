#pragma once

#include <Asteroids.h>
#include "SceneInterface.h"

class GameOverScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;

 public:
  void render(WindowRendererInterface *renderer) override;
  void onVisible() override;

  ~GameOverScene() override {}

  explicit GameOverScene(Asteroids *game) {
    this->game = game;
  }

  void onAction(InputAction action, bool once) override;
};