#include <SFML/Graphics/Text.hpp>
#include <utility/drawing.h>
#include "GameOverScene.h"
#include "MainMenuScene.h"

void GameOverScene::render(WindowRendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto font = renderer->getFont();

  sf::Text startTitleText("Game Over", font, 16);
  sf::Text startPromptText("Press Fire to return to the main menu", font, 16);

  auto center = view.getSize().x / 2;
  auto middle = view.getSize().y / 2;

  drawing::centreText(startTitleText);
  drawing::centreText(startPromptText);

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
    game->setScene(new MainMenuScene(game));
  }
}

GameOverScene::GameOverScene(Asteroids *game) {
  this->game = game;
}

GameOverScene::~GameOverScene() {
  game->getControllers().getFirst()->setDelegate(nullptr);
}
