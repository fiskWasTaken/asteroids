#include <SFML/Graphics/Text.hpp>
#include "GameOverScene.h"
#include "GameScene.h"

void GameOverScene::render(WindowRendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto font = renderer->getFont();

  sf::Text startTitleText("Game Over", font, 16);
  sf::Text startPromptText("Press C to retry", font, 16);
  sf::Text highScorePromptText("Press E to view high score tables", font, 16);

  auto center = view.getSize().x / 2;
  auto middle = view.getSize().y / 2;

  startTitleText.setPosition(center, middle - 14);
  startPromptText.setPosition(center, middle);

  window->draw(startTitleText);
  window->draw(startPromptText);
}

void GameOverScene::onVisible() {
  game->getSessions()->clear();
  game->getControllers().getFirstAvailable()->setDelegate(this);
}

void GameOverScene::onAction(InputAction action, bool once) {
  if (action == InputAction::FIRE && once) {
    game->setScene(new GameScene(game));
  }
}

GameOverScene::GameOverScene(Asteroids *game) {
  this->game = game;
}

GameOverScene::~GameOverScene() {
  game->getControllers().getFirst()->setDelegate(nullptr);
}
