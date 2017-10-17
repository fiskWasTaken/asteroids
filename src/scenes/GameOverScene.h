//
// Created by Fisk on 13/10/2017.
//

#ifndef ASTEROIDS_GAMEOVERSCENE_H
#define ASTEROIDS_GAMEOVERSCENE_H

#include "SceneInterface.h"
class GameOverScene : public SceneInterface {
 public:
  void render(Renderer *renderer) override;
  void handleEvents() override;
  void onVisible() override;
  void onDestroy() override;
};

#endif //ASTEROIDS_GAMEOVERSCENE_H
