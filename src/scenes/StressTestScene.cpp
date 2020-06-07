#include <SFML/Graphics/Text.hpp>
#include <waves/WaveGenerator.h>
#include "StressTestScene.h"
#include "MainMenuScene.h"

void StressTestScene::onAction(InputAction action, bool once)
{
  if (action == InputAction::FIRE && once)
  {
    game->setScene(new MainMenuScene(game));
  }
}