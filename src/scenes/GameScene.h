//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_SCENES_GAMESCENE_H
#define ASTEROIDS_SCENES_GAMESCENE_H

#include "SceneInterface.h"

class GameScene : public SceneInterface {
 private:
  Asteroids *game;
 public:
  GameScene(Asteroids *game) { this->game = game; }
  void handleEvents() override;
  void render(Renderer *renderer) override;
  void onVisible() override;
  void onDestroy() override;
};

#endif //ASTEROIDS_SCENES_GAMESCENE_H
