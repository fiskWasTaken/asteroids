//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_SCENES_GAMESCENE_H
#define ASTEROIDS_SCENES_GAMESCENE_H

#include <Asteroids.h>
#include "SceneInterface.h"

class GameScene : public SceneInterface {
 private:
  Asteroids *game;
 public:
  explicit GameScene(Asteroids *game) { this->game = game; }
  void handleEvents() override;
  void render(RendererInterface *renderer) override;
  void onVisible() override;
  void onDestroy() override;

  void drawHud(RendererInterface *renderer);
  void drawWorld(RendererInterface *renderer);
};

#endif //ASTEROIDS_SCENES_GAMESCENE_H
