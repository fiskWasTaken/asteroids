//
// Created by fisk on 21/09/17.
//

#include <sstream>
#include "GameScene.h"
#include "../entities/Asteroid.h"

void GameScene::render(Renderer *renderer) {
  auto game = renderer->getGame();
  auto window = renderer->getWindow();

  auto world = game->getWorld();
  auto vec = sf::Vector2f((float) world->getWidth(), (float) world->getHeight());
  sf::RectangleShape shape(vec);
  shape.setFillColor(sf::Color::Black);
  window->draw(shape);

  auto session = game->getSessions()[0];

  drawWorld(renderer);
  drawHud(renderer);
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

  auto ast = new Asteroid(world);
  ast->pos.x = 5;
  ast->pos.y = 5;
  ast->vel.x = 2;
  ast->vel.y = 1;

  auto ast2 = new Asteroid(world);
  ast2->pos.x = 55;
  ast2->pos.y = 300;
  ast2->vel.x = -1.5F;
  ast2->vel.y = 1;

  auto ast3 = new Asteroid(world);
  ast3->pos.x = 200;
  ast3->pos.y = 300;
  ast3->vel.x = -1.5F;
  ast3->vel.y = -1;

  auto controller = game->getDefaultController();
  player->setController(controller);

  world->pushObject(ast);
  world->pushObject(ast2);
  world->pushObject(ast3);

  session->spawnShip(world);

  game->getSessions()->push_back(session);

  // playerSession 2 stuff -- cool, it works, but we don't want to do this just yet :>
//  auto player2 = new Player("Player 2");
//  auto session2 = new PlayerSession(player2);
//  auto ship2 = new Ship(player2);
//  ship2->pos.x = 200;
//  ship2->pos.y = 100;
//  ship2->setWidth(16);
//  ship2->setHeight(16);
//
//  auto controller2 = new KeyboardController();
//  controller2->assignKeyForAction(InputAction::ACCELERATE, sf::Keyboard::Up);
//  controller2->assignKeyForAction(InputAction::BRAKE, sf::Keyboard::Down);
//  controller2->assignKeyForAction(InputAction::LEFT, sf::Keyboard::Left);
//  controller2->assignKeyForAction(InputAction::RIGHT, sf::Keyboard::Right);
//  controller2->assignKeyForAction(InputAction::FIRE, sf::Keyboard::RShift);
//  controller2->setDelegate(ship2);
//
//  player2->setController(controller2);
//
//  world->pushObject(ship2);
//  game->getSessions()->push_back(session2);
}

void GameScene::onDestroy() {

}

void GameScene::drawHud(Renderer *renderer) {
  auto font = renderer->getFont();
  auto window = renderer->getWindow();
  int offset = 4;

  for (auto session: *game->getSessions()) {
    std::stringstream score;
    std::stringstream lives;
    score << "Score: " << session->getScore();
    lives << "Lives: " << session->getLives();

    sf::Text nameText(session->getPlayer()->getName(), *font, 16);
    sf::Text scoreText(score.str(), *font, 16);
    sf::Text livesText(lives.str(), *font, 16);

    nameText.setPosition(offset, 0);
    scoreText.setPosition(offset, 14);
    livesText.setPosition(offset, 28);

    window->draw(nameText);
    window->draw(scoreText);
    window->draw(livesText);

    offset += 64;
  }
}
void GameScene::drawWorld(Renderer *renderer) {
  auto world = game->getWorld();
  auto window = renderer->getWindow();

  for (auto entity: world->getObjects()) {
    auto shape = entity->getDrawable();
    window->draw(*shape);
  }
}
