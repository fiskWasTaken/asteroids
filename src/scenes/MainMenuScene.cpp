#include <SFML/Graphics/Text.hpp>
#include <entities/asteroids/LargeAsteroid.h>
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

  drawWorld(renderer);
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

  for (int i = 0; i < 40; i++) {
    auto ast = new LargeAsteroid(world);
    ast->pos.x = 50 * rand() % 600;
    ast->pos.y = -50 * rand() % 400;
    ast->vel.x = rand() % 100 / 80;
    ast->vel.y = rand() % 100 / 80;

    world->pushObject(ast);
  }
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
