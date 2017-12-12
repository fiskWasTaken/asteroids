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

  sf::Text startTitleText("Asteroids", font, 16);
  sf::Text startPromptText("Press C to start", font, 16);
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
  controller->poll();
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
  controller->setDelegate(this);

  LevelLoader loader;
  loader.load(world, {
      "Main menu background",
      10,
      10,
      10
  });
}

void MainMenuScene::main() {
  world->update();
}