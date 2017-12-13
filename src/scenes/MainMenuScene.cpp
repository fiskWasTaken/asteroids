#include <SFML/Graphics/Text.hpp>
#include <entities/asteroids/LargeAsteroid.h>
#include <levels/LevelLoader.h>
#include <sstream>
#include <SFML/Graphics/ConvexShape.hpp>
#include "MainMenuScene.h"
#include "GameScene.h"
#include "HighScoreTableScene.h"

void MainMenuScene::render(WindowRendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto font = renderer->getFont();

  std::string startPromptString = "Press " + game->getControllers().getFirst()->getKeyString(InputAction::FIRE) + " to start";

  sf::Text startTitleText("Asteroids", font, 16);
  sf::Text startPromptText(startPromptString, font, 16);
  sf::Text startLicenseText("fisk, 2017", font, 16);

  auto center = view.getSize().x / 2;
  auto middle = view.getSize().y / 2;

  startTitleText.setPosition(center, middle - 14);
  startPromptText.setPosition(center, middle);
  startLicenseText.setPosition(center, middle + 14);

  worldRenderer.drawWorld(renderer, world);
  worldRenderer.drawTimings(renderer);

  window->draw(startTitleText);
  window->draw(startPromptText);
  window->draw(startLicenseText);
}

void MainMenuScene::handleEvents() {
  game->getControllers().getFirst()->poll();
}

void MainMenuScene::onAction(InputAction action) {
  if (action == InputAction::FIRE) {
    game->setScene(new GameScene(game));
  }

  if (action == InputAction::ALTFIRE) {
    game->setScene(new HighScoreTableScene(game));
  }
}

void MainMenuScene::onVisible() {
  game->getControllers().getFirst()->setDelegate(this);

  LevelLoader loader;
  loader.load(world, {
      "Main menu background/stress test",
      20,
      20,
      20
  });
}

void MainMenuScene::main() {
  world->update();
}