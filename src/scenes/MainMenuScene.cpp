//
// Created by fisk on 21/09/17.
//

#include <SFML/Graphics/Text.hpp>
#include "MainMenuScene.h"
#include "GameScene.h"
#include "HighScoreTableScene.h"

void MainMenuScene::render(RendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto font = renderer->getFont();

  sf::Text startTitleText("Asteroids", *font, 16);
  sf::Text startPromptText("Press C to start", *font, 16);
  sf::Text startLicenseText("fisk, 2017", *font, 16);

  auto center = view.getSize().x / 2;
  auto middle = view.getSize().y / 2;

  startTitleText.setPosition(center, middle - 14);
  startPromptText.setPosition(center, middle);
  startLicenseText.setPosition(center, middle + 14);

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
}
void MainMenuScene::onDestroy() {
  delete (controller);
}
