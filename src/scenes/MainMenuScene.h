#pragma once

#include <Asteroids.h>
#include <renderer/WorldRenderer.h>
#include <functional>
#include "SceneInterface.h"

struct menu_option_t {
  std::string string;
  std::function<void(void)> onSelect;
};

class MainMenuScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;
  World *world;

  WorldRenderer worldRenderer;

  std::vector<menu_option_t> menuOptions;
  int selectedMenuOption = 0;
 public:
  explicit MainMenuScene(Asteroids *game) {
    this->game = game;
    world = new World(game, 640, 480);
  }
  void render(WindowRendererInterface *renderer) override;
  void handleEvents() override;
  void onAction(InputAction action) override;
  void onVisible() override;
  void main() override;

  ~MainMenuScene() override {
    game->getControllers().getFirst()->setDelegate(nullptr);
    delete world;
  }
};
