//
// Created by Fisk on 13/10/2017.
//

#include <SFML/Graphics/Text.hpp>
#include "GameOverScene.h"

void GameOverScene::render(RendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto font = renderer->getFont();

  sf::Text startTitleText("Game Over", *font, 16);
  sf::Text startPromptText("Press C to retry", *font, 16);
  sf::Text highScorePromptText("Press E to view high score tables", *font, 16);

  auto center = window->getSize().x / 2;
  auto middle = window->getSize().y / 2;

  startTitleText.setPosition(center, middle - 14);
  startPromptText.setPosition(center, middle);

  window->draw(startTitleText);
  window->draw(startPromptText);
}

void GameOverScene::handleEvents() {

}
void GameOverScene::onVisible() {

}
void GameOverScene::onDestroy() {

}
