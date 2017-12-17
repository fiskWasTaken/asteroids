#include <SFML/Graphics/Text.hpp>
#include <sstream>
#include <SFML/Graphics/ConvexShape.hpp>
#include "MainMenuScene.h"
#include "GameScene.h"
#include "StressTestScene.h"

void MainMenuScene::render(WindowRendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto font = renderer->getFont();

  std::string
      startPromptString = "Press " + game->getControllers().getFirst()->getKeyString(InputAction::FIRE) + " to start";

  sf::Text startTitleText("Asteroids", font, 16);
  sf::Text startPromptText(startPromptString, font, 16);
  sf::Text startLicenseText("fisk, 2017", font, 16);

  auto center = view.getSize().x / 2;
  auto middle = view.getSize().y / 2;

  startTitleText.setPosition(center, middle - 14);
  startPromptText.setPosition(center, middle);
  startLicenseText.setPosition(center, middle + 14);

  worldRenderer.drawWorld(renderer, &world);

  window->draw(startTitleText);
  window->draw(startPromptText);
  window->draw(startLicenseText);
}

void MainMenuScene::onAction(InputAction action, bool once) {
  if (action == InputAction::FIRE && once) {
    game->setScene(new GameScene(game));
  }

  if (action == InputAction::PANIC && once) {
    game->setScene(new StressTestScene(game));
  }
}

void MainMenuScene::onVisible() {
  game->getControllers().getFirst()->setDelegate(this);

  WaveGenerator generator;

  generator.generate(&world, 90);
}

void MainMenuScene::main() {
  world.update();
}