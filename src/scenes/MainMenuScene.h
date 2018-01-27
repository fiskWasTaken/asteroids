#pragma once

#include <Asteroids.h>
#include <renderer/WorldRenderer.h>
#include <functional>
#include "SceneInterface.h"
#include <SFML/Graphics/Shader.hpp>

struct menu_option_t {
  std::string string;
  std::function<void(Asteroids*)> onSelect;
};

class MainMenuScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;
  World world;
  WorldRenderer worldRenderer;
  std::vector<menu_option_t> menuOptions;
  int selectedMenuOption = 0;
  sf::Shader shader;
  sf::Clock clock;

 public:
  explicit MainMenuScene(Asteroids *game);
  void render(WindowRendererInterface *renderer) override;
  void onAction(InputAction action, bool once) override;
  void onVisible() override;
  void main() override;

  ~MainMenuScene() override;
};
