#pragma once

#include <IGame.h>
#include <renderer/WorldRenderer.h>
#include <functional>
#include "IScene.h"
#include <SFML/Graphics/Shader.hpp>

struct menu_option_t {
  std::string string;
  std::function<void(IGame*)> onSelect;
};

class MainMenuScene : public IScene, public IControllerListener {
 protected:
  IGame *game;
  World world;
  WorldRenderer worldRenderer;
  std::vector<menu_option_t> menuOptions;
  int selected = 0;
  sf::Shader shader;
  sf::Clock clock;

 public:
  explicit MainMenuScene(IGame *game);
  void render(IWindowRenderer *renderer) override;
  void onAction(InputAction action, bool once) override;
  void onVisible() override;
  void main() override;

  ~MainMenuScene() override;
};
