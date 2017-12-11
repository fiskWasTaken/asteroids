//
// Created by fisk on 21/09/17.
//

#include <sstream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include "GameScene.h"
#include "entities/asteroids/LargeAsteroid.h"
#include "GameOverScene.h"

void GameScene::render(RendererInterface *renderer) {
  auto window = renderer->getWindow();

  auto vec = sf::Vector2f((float) world->getWidth(), (float) world->getHeight());
  sf::RectangleShape shape(vec);
  shape.setFillColor(sf::Color::Black);
  window->draw(shape);

  auto session = game->getSessions()[0];

  drawWorld(renderer);
  drawHud(renderer);
//  drawDebug(renderer);
}

void GameScene::drawDebug(RendererInterface *renderer) {
  auto window = renderer->getWindow();

  for (auto obj : world->getObjects()) {
    auto points = getOffsetPoints(obj);
    // create an empty shape
    auto shep = new sf::ConvexShape();

    shep->setPointCount(points.size());

    for (int i = 0; i < points.size(); i++) {
      shep->setPoint(i, points[i]);
    }

    shep->setFillColor(sf::Color::Transparent);
    shep->setOutlineColor(sf::Color::Red);
    shep->setOutlineThickness(1.0F);
    window->draw(*shep);
  }
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

  for (int i = 0; i < 10; i++) {
    auto ast = new LargeAsteroid(world);
    ast->pos.x = 50 * rand() % 600;
    ast->pos.y = -50 * rand() % 400;
    ast->vel.x = rand() % 100 / 80;
    ast->vel.y = rand() % 100 / 80;

    world->pushObject(ast);
  }

  auto controller = game->getDefaultController();
  player->setController(controller);

  session->spawnShip(world);

  game->getSessions()->push_back(session);

//   playerSession 2 stuff -- cool, it works, but we don't want to do this just yet :>
//  auto player2 = new Player("Player 2");
//  auto session2 = new PlayerSession(player2);
//  auto ship2 = new Ship(world, session2);
//  ship2->pos.x = 200;
//  ship2->pos.y = 100;
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

void GameScene::drawHud(RendererInterface *renderer) {
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

  if (paused) {
    auto view = renderer->getView();

    sf::Text pausedText("Paused", *font, 16);

    auto center = view.getSize().x / 2;
    auto middle = view.getSize().y / 2;

    pausedText.setPosition(center, middle - 14);
    window->draw(pausedText);
  }
}

void GameScene::drawWorld(RendererInterface *renderer) {
  auto window = renderer->getWindow();

  for (auto entity: world->getObjects()) {
    entity->renderTo(window);
  }
}

void GameScene::pause(PlayerSession *initiator) {
  paused = true;
  pauseInitiator = initiator;
  initiator->getPlayer()->getController()->setDelegate(this);
}

void GameScene::main() {
  if (!paused) {
    world->update();

    for (auto respawnTimer : respawnTimers) {
      auto session = respawnTimer.first;
      respawnTimers[session]--;

      if (respawnTimers[session] == 0) {
        respawnTimers.erase(session);
        session->setLives(session->getLives() - 1);

        if (session->getLives() == 0) {
          onGameOver(session);
        } else {
          session->spawnShip(world);
        }
      }
    }
  }
}

void GameScene::onAction(InputAction action) {
  if (action == InputAction::PAUSE) {
    paused = false;
    pauseInitiator->getPlayer()->getController()->setDelegate(pauseInitiator->getShip());
  }
}

void GameScene::onGameOver(PlayerSession *playerSession) {
  // todo: support multiple players (wait until everyone dies for good)
  game->setScene(new GameOverScene(game));
}

void GameScene::onShipDestroyed(PlayerSession *playerSession) {
  playerSession->getPlayer()->getController()->setDelegate(nullptr);
  startRespawnTimer(playerSession);
}

void GameScene::startRespawnTimer(PlayerSession *playerSession) {
  respawnTimers[playerSession] = respawnTime;
}
