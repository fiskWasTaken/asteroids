//
// Created by Fisk on 13/10/2017.
//

#ifndef ASTEROIDS_HIGHSCORETABLESCENE_H
#define ASTEROIDS_HIGHSCORETABLESCENE_H

#include "SceneInterface.h"
class HighScoreTableScene : public SceneInterface  {private:
 private:
  Asteroids *game;
  Controller *controller;

 public:
  HighScoreTableScene(Asteroids *game) {
    this->game = game;
    this->controller = game->getDefaultController();
  }
  void render(Renderer *renderer) override;
  void handleEvents() override;
  void onVisible() override;
  void onDestroy() override;
};

#endif //ASTEROIDS_HIGHSCORETABLESCENE_H
