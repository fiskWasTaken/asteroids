#pragma once

#include <Asteroids.h>
#include "SceneInterface.h"
class MainMenuScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;
  ControllerInterface *controller;
  World *world;
 public:
  explicit MainMenuScene(Asteroids *game) {
    this->game = game;
    controller = game->getDefaultController();
    world = new World(game, 640, 480);
  }
  void render(RendererInterface *renderer) override;
  void handleEvents() override;
  void onAction(InputAction action) override;
  void onVisible() override;
  void drawWorld(RendererInterface *renderer);
  void main() override;

  ~MainMenuScene() override {
    delete controller;
    delete world;
  }
};
