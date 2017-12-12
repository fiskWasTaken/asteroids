#include <SFML/Graphics/Text.hpp>
#include <entities/asteroids/LargeAsteroid.h>
#include <levels/LevelLoader.h>
#include <sstream>
#include "MainMenuScene.h"
#include "GameScene.h"
#include "HighScoreTableScene.h"

void MainMenuScene::render(RendererInterface *renderer) {
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

  drawWorld(renderer);
  drawTimings(renderer);
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

void MainMenuScene::drawWorld(RendererInterface *renderer) {
  auto window = renderer->getWindow();

  for (auto entity: world->getObjects()) {
    entity->renderTo(window);
  }
}

void MainMenuScene::main() {
  world->update();
}

void MainMenuScene::drawTimings(RendererInterface *renderer) {
  auto font = renderer->getFont();
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto newTime = clock.getElapsedTime();
  std::stringstream frameTime;
  frameTime << "Frame time: " << (newTime.asMicroseconds() - lastFrameTime.asMicroseconds());
  sf::Text timingText(frameTime.str(), font, 16);
  timingText.setPosition(4, view.getSize().y - 16);
  window->draw(timingText);
  lastFrameTime = newTime;
}