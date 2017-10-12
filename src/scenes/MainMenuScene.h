//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_SCENES_MAINMENU_H
#define ASTEROIDS_SCENES_MAINMENU_H

#include "SceneInterface.h"
class MainMenuScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;
  Controller *controller;
 public:
  MainMenuScene(Asteroids *game) {
    this->game = game;
    this->controller = game->getDefaultController();
  }
  void render(Renderer *renderer) override;
  void handleEvents() override;
  void onAction(InputAction action) override;
  void onVisible() override;
  void onDestroy() override;
};

#endif //ASTEROIDS_MAINMENU_H
