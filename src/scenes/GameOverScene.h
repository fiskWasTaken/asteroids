#pragma once

#include <Asteroids.h>
#include "SceneInterface.h"

class GameOverScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;

 public:
  explicit GameOverScene(Asteroids *game);
  ~GameOverScene() override;

  void render(WindowRendererInterface *renderer) override;
  void onVisible() override;
  void onAction(InputAction action, bool once) override;
};