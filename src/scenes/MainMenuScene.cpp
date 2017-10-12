//
// Created by fisk on 21/09/17.
//

#include "MainMenuScene.h"
#include "GameScene.h"

void drawIntroScreen(sf::RenderWindow *window, sf::Font *font) {
  sf::Text startTitleText("Asteroids", *font, 16);
  sf::Text startPromptText("Press C to start", *font, 16);
  sf::Text startLicenseText("fisk, 2017", *font, 16);

  auto center = window->getSize().x / 2;
  auto middle = window->getSize().y / 2;

  startTitleText.setPosition(center, middle - 14);
  startPromptText.setPosition(center, middle);
  startLicenseText.setPosition(center, middle + 14);

  window->draw(startTitleText);
  window->draw(startPromptText);
  window->draw(startLicenseText);
}

void MainMenuScene::render(Renderer *renderer) {
  auto window = renderer->getWindow();

  drawIntroScreen(window, renderer->getFont());
}

void MainMenuScene::handleEvents() {
  controller->poll();
}

void MainMenuScene::onAction(InputAction action) {
  if (action == InputAction::FIRE) {
    game->setScene(new GameScene(game));
  }
}

void MainMenuScene::onVisible() {
  controller->setDelegate(this);
}
void MainMenuScene::onDestroy() {
  delete(controller);
}
