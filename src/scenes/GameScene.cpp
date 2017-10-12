//
// Created by fisk on 21/09/17.
//

#include "GameScene.h"
#include "../entities/Asteroid.h"
#include "../entities/Ship.h"

void drawWorld(sf::RenderWindow *window, World *world) {
  for (auto entity: world->getObjects()) {
    sf::RectangleShape shep(sf::Vector2f((float) entity->getWidth(), (float) entity->getHeight()));
    shep.setFillColor(sf::Color::Transparent);
    shep.setOutlineColor(sf::Color::Green);
    shep.setOutlineThickness(1.0F);
    shep.setPosition(entity->pos);
    shep.setOrigin(entity->getWidth() / 2, entity->getHeight() / 2);
    shep.setRotation(entity->rot);
    window->draw(shep);
  }
}

void drawHud(sf::RenderWindow *window, sf::Font *font) {
  sf::Text scoreText("Score: 0", *font, 16);
  sf::Text livesText("Lives: 3", *font, 16);

  scoreText.setPosition(4, 0);
  livesText.setPosition(4, 14);

  window->draw(scoreText);
  window->draw(livesText);
}

void GameScene::render(Renderer *renderer) {
  auto game = renderer->getGame();
  auto window = renderer->getWindow();
  auto font = renderer->getFont();

  auto world = game->getWorld();
  auto vec = sf::Vector2f((float) world->getWidth(), (float) world->getHeight());
  sf::RectangleShape shape(vec);
  shape.setFillColor(sf::Color::Black);
  window->draw(shape);

  auto session = game->getSessions()[0];

  drawWorld(window, world);
  drawHud(window, font);
}

void GameScene::handleEvents() {
  for (auto session : *game->getSessions()) {
    auto controller = session->getPlayer()->getController();

    if (controller != nullptr) {
      controller->poll();
    }
  }
}

void GameScene::onVisible() {
  auto player = new Player("Player 1");
  auto session = new PlayerSession(player);

  auto world = game->getWorld();

  auto ast = new Asteroid();
  ast->pos.x = 5;
  ast->pos.y = 5;
  ast->vel.x = 2;
  ast->vel.y = 1;
  ast->setHeight(32);
  ast->setWidth(32);

  auto ast2 = new Asteroid();
  ast2->pos.x = 55;
  ast2->pos.y = 300;
  ast2->vel.x = -1.5F;
  ast2->vel.y = 1;
  ast2->setHeight(32);
  ast2->setWidth(32);

  auto ast3 = new Asteroid();
  ast3->pos.x = 200;
  ast3->pos.y = 300;
  ast3->vel.x = -1.5F;
  ast3->vel.y = -1;
  ast3->setHeight(32);
  ast3->setWidth(32);

  auto ship = new Ship(player);
  ship->pos.x = 100;
  ship->pos.y = 100;
  ship->setHeight(16);
  ship->setWidth(16);

  auto controller = game->getDefaultController();
  player->setController(controller);
  controller->setDelegate(ship);

  world->pushObject(ship);
  world->pushObject(ast);
  world->pushObject(ast2);
  world->pushObject(ast3);

  game->getSessions()->push_back(session);
}

void GameScene::onDestroy() {

}
