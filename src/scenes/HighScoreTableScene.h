#pragma once

#include <Asteroids.h>
#include "SceneInterface.h"
class HighScoreTableScene : public SceneInterface {
 private:
 private:
  Asteroids *game;

 public:
  explicit HighScoreTableScene(Asteroids *game) {
    this->game = game;
  }

  void render(WindowRendererInterface *renderer) override;
  void onVisible() override;
};
