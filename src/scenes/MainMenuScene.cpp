#include <SFML/Graphics/Text.hpp>
#include <sstream>
#include <SFML/Graphics/ConvexShape.hpp>
#include "MainMenuScene.h"
#include "GameScene.h"
#include "StressTestScene.h"

void centreText(sf::Text &text) {
  auto bounds = text.getLocalBounds();
  text.setOrigin(sf::Vector2f(int(bounds.left + bounds.width / 2), 0));
}

void MainMenuScene::render(WindowRendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto font = renderer->getFont();

  std::string
      startPromptString = "Press " + game->getControllers().getFirst()->getKeyString(InputAction::FIRE) + " to start";

  sf::Text startTitleText("Asteroids", font, 16);
  sf::Text startPromptText(startPromptString, font, 16);
  sf::Text startLicenseText("fisk, 2017", font, 16);
  sf::Text menuOptionText("< " + menuOptions[selectedMenuOption].string + " >", font, 16);

  auto center = view.getSize().x / 2;
  auto middle = view.getSize().y / 2;

  startTitleText.setPosition(center, middle - 32);
  menuOptionText.setPosition(center, middle);
  startPromptText.setPosition(center, middle + 16);
  startLicenseText.setPosition(center, view.getSize().y - 24);

  centreText(startTitleText);
  centreText(startPromptText);
  centreText(startLicenseText);
  centreText(menuOptionText);

  worldRenderer.drawWorld(renderer, &world);

  window->draw(startTitleText);
  window->draw(startPromptText);
  window->draw(startLicenseText);
  window->draw(menuOptionText);
}

void MainMenuScene::onAction(InputAction action, bool once) {
  if (action == InputAction::FIRE && once) {
    menuOptions[selectedMenuOption].onSelect(game);
  }

  if (action == InputAction::LEFT && once) {
    selectedMenuOption--;

    if (selectedMenuOption < 0) {
      selectedMenuOption = static_cast<int>(menuOptions.size() - 1);
    }
  }

  if (action == InputAction::RIGHT && once) {
    selectedMenuOption++;

    if (selectedMenuOption >= menuOptions.size()) {
      selectedMenuOption = 0;
    }
  }
}

void MainMenuScene::onVisible() {
  game->getControllers().getFirst()->setDelegate(this);
  WaveGenerator generator;
  generator.generate(&world, 10);
}

void MainMenuScene::main() {
  world.update();
}
MainMenuScene::~MainMenuScene() {
  game->getControllers().getFirst()->setDelegate(nullptr);
}

MainMenuScene::MainMenuScene(Asteroids *game) : world(game, 640, 480) {
  this->game = game;

  menu_option_t onePlayer;
  onePlayer.string = "1 Player";
  onePlayer.onSelect = [](Asteroids *game) {
    game->setScene(new GameScene(game));
  };

  menu_option_t twoPlayers;
  twoPlayers.string = "2 Players";
  twoPlayers.onSelect = [](Asteroids *game) {
    game->setScene(new GameScene(game));
  };

  menu_option_t benchmark;
  benchmark.string = "Stress Test";
  benchmark.onSelect = [](Asteroids *game) {
    game->setScene(new StressTestScene(game));
  };

  this->menuOptions.push_back(onePlayer);
  this->menuOptions.push_back(twoPlayers);
  this->menuOptions.push_back(benchmark);
}
