#include <levels/LevelLoader.h>
#include <SFML/Graphics/Text.hpp>
#include "StressTestScene.h"
#include "MainMenuScene.h"

void StressTestScene::render(WindowRendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto font = renderer->getFont();

  sf::Text startTitleText("Stress test", font, 16);

  startTitleText.setPosition(4, 0);

  worldRenderer.drawWorld(renderer, world);
  worldRenderer.drawTimings(renderer);

  window->draw(startTitleText);
}

void StressTestScene::onAction(InputAction action, bool once) {
  if (action == InputAction::PANIC && once) {
    game->setScene(new MainMenuScene(game));
  }
}

void StressTestScene::onVisible() {
  game->getControllers().getFirst()->setDelegate(this);

  LevelLoader loader;
  loader.load(world, {
      "Stress test",
      0,
      0,
      0,
      500
  });
}

void StressTestScene::main() {
  world->update();
}
