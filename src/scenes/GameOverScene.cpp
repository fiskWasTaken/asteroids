#include <SFML/Graphics/Text.hpp>
#include <utility/drawing.h>
#include "GameOverScene.h"
#include "MainMenuScene.h"

void GameOverScene::onAction(InputAction action, bool once) {
  if (action == InputAction::FIRE && once) {
    game->setScene(new MainMenuScene(game));
  }
}