#include <sstream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <levels/Playlist.h>
#include <levels/LevelLoader.h>
#include <input/KeyboardController.h>
#include "GameScene.h"
#include "GameOverScene.h"

void GameScene::render(WindowRendererInterface *renderer) {
  worldRenderer.drawBg(renderer, world);
  worldRenderer.drawWorld(renderer, world);
  worldRenderer.drawTimings(renderer);

  drawHud(renderer);
}

void GameScene::loadCurrentLevel() {
  LevelLoader loader;
  auto level = game->getPlaylist().getLevel();
  loader.load(world, level);
  showLevelTextTimeout = LEVEL_TEXT_DISPLAY_TIME;

  for (auto session : *game->getSessions()) {
    session->getShip()->setInvincibilityCooldown(100);
  }
}

void GameScene::onVisible() {
  auto player = new Player("Player 1");
  auto session = new PlayerSession(player);
  player->setController(game->getControllers().getFirstAvailable());
  session->spawnShip(world);
  game->getSessions()->push_back(session);

  auto player2 = new Player("Player 2");
  player2->setColor(sf::Color(58, 144, 163));
  auto session2 = new PlayerSession(player2);
  player2->setController(game->getControllers().getFirstAvailable());
  session2->spawnShip(world);
  game->getSessions()->push_back(session2);

  game->getPlaylist().rewind();
  loadCurrentLevel();
}

void GameScene::drawHud(WindowRendererInterface *renderer) {
  auto font = renderer->getFont();
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  int offset = 4;

  for (auto session: *game->getSessions()) {
    sf::Text nameText(session->getPlayer()->getName(), font, 16);
    sf::Text scoreText("Score: " + std::to_string(session->getScore()), font, 16);
    sf::Text livesText("Lives: " + std::to_string(session->getLives()), font, 16);

    nameText.setFillColor(session->getPlayer()->getColor());

    nameText.setPosition(offset, 0);
    scoreText.setPosition(offset, 14);
    livesText.setPosition(offset, 28);

    window->draw(nameText);
    window->draw(scoreText);
    window->draw(livesText);

    offset += 96;
  }

  if (paused) {
    sf::Text pausedText("Paused", font, 16);

    auto center = view.getSize().x / 2;
    auto middle = view.getSize().y / 2;

    pausedText.setPosition(center, middle - 14);
    window->draw(pausedText);
  }

  if (showLevelTextTimeout > 0) {
    sf::Text levelText(game->getPlaylist().getLevel().name, font, 16);

    auto center = view.getSize().x / 2;
    auto middle = view.getSize().y / 2;

    levelText.setPosition(center, middle - 14);
    window->draw(levelText);

    showLevelTextTimeout--;
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
    updateRespawnTimers();

    int remainingAsteroids = 0;

    for (auto object : world->getObjects()) {
      if (object->getClass() == WorldObjectClass::ASTEROID) {
        remainingAsteroids++;
      }
    }

    if (remainingAsteroids == 0) {
      auto next = game->getPlaylist().next();

      if (!next) {
        game->setScene(new GameOverScene(game));
      } else {
        loadCurrentLevel();
      }
    }
  }
}

void GameScene::updateRespawnTimers() {
  for (auto it = respawnTimers.begin(); it != respawnTimers.end(); ++it) {
    auto session = (*it).first;
    respawnTimers[session]--;

    if (respawnTimers[session] == 0) {
      session->setLives(session->getLives() - 1);

      if (session->getLives() == 0) {
        onGameOver(session);
      } else {
        session->spawnShip(world);
      }

      respawnTimers.erase(session);
    }
  }
}

void GameScene::onAction(InputAction action, bool once) {
  if (action == InputAction::PAUSE && once) {
    paused = false;
    pauseInitiator->getPlayer()->getController()->setDelegate(pauseInitiator->getShip());
  }
}

void GameScene::onGameOver(PlayerSession *playerSession) {
  if (getRemainingPlayerCount() == 0)
    game->setScene(new GameOverScene(game));
}

void GameScene::onShipDestroyed(PlayerSession *playerSession) {
  playerSession->getPlayer()->getController()->setDelegate(nullptr);
  startRespawnTimer(playerSession);
}

void GameScene::startRespawnTimer(PlayerSession *playerSession) {
  respawnTimers[playerSession] = RESPAWN_TIME;
}

int GameScene::getRemainingPlayerCount() {
  int count = 0;

  for (auto session : *game->getSessions())
    if (session->getLives() == 0)
      count++;

  return count;
}
