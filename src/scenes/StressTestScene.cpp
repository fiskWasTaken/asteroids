#include <SFML/Graphics/Text.hpp>
#include <waves/WaveGenerator.h>
#include "StressTestScene.h"
#include "MainMenuScene.h"

void StressTestScene::render(WindowRendererInterface *renderer) {
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  auto font = renderer->getFont();

  sf::Text startTitleText("Stress test", font, 16);

  startTitleText.setPosition(4, 0);

  worldRenderer.drawWorld(renderer, &world);
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

  WaveGenerator generator;
  generator.generate(&world, 500);
}

void StressTestScene::main() {
  world.update();
}

StressTestScene::~StressTestScene() {
  game->getControllers().getFirst()->setDelegate(nullptr);
}

StressTestScene::StressTestScene(Asteroids *game) : world(game, 640, 480) {
  this->game = game;
}
