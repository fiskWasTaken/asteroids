#include <sstream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <input/KeyboardController.h>
#include "GameScene.h"
#include "GameOverScene.h"

void GameScene::render(WindowRendererInterface *renderer) {
  worldRenderer.drawBg(renderer, &world);
  worldRenderer.drawWorld(renderer, &world);

  drawHud(renderer);
  drawWaveBar();
}

void GameScene::startWave() {
  showWaveTextTimeout = WAVE_TEXT_DISPLAY_TIME;
  waveGenerator.generate(&world, waveId);

  for (const auto &session : *game->getSessions()) {
    session->getShip()->setInvincibilityCooldown(100);
  }
}

void GameScene::onVisible() {
  auto player = new Player("Player 1");
  PlayerSession session(player);
  auto sessionPtr = std::make_shared<PlayerSession>(session);
  player->setController(game->getControllers().getFirstAvailable());
  sessionPtr->spawnShip(&world);
  game->getSessions()->push_back(sessionPtr);

//  auto player2 = new Player("Player 2");
//  player2->setColor(sf::Color(58, 144, 163));
//  auto session2 = new PlayerSession(player2);
//  player2->setController(game->getControllers().getFirstAvailable());
//  session2->spawnShip(world);
//  game->getSessions()->push_back(session2);

  startWave();
}

void GameScene::drawHud(WindowRendererInterface *renderer) {
  auto font = renderer->getFont();
  auto window = renderer->getWindow();
  auto view = renderer->getView();
  int offset = 4;

  for (const auto &session: *game->getSessions()) {
    sf::Text nameText(session->getPlayer()->getName(), font, 14);
    sf::Text scoreText("Score: " + std::to_string(session->getScore()), font, 14);

    // Bing bing wahoo
    std::stringstream marios;

    for (int i = 0; i < session->getLives(); i++) {
      marios << "^";
    }

    sf::Text livesText(marios.str(), font, 14);

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
    sf::Text pausedText("[Paused]", font, 16);

    auto center = view.getSize().x / 2;
    auto middle = view.getSize().y / 2;

    pausedText.setPosition(center, middle - 14);
    window->draw(pausedText);
  }

  if (showWaveTextTimeout > 0) {
    sf::Text waveText("Wave " + std::to_string(waveId), font, 16);
    sf::Text readyText("Ready!", font, 16);

    auto center = view.getSize().x / 2;
    auto middle = view.getSize().y / 2;

    waveText.setPosition(center, middle - 8);
    readyText.setPosition(center, middle + 8);
    window->draw(waveText);
    window->draw(readyText);

    showWaveTextTimeout--;
  }
}

void GameScene::pause(PlayerSession *initiator) {
  paused = true;
  pauseInitiator = initiator;
  initiator->getPlayer()->getController()->setDelegate(this);
}

void GameScene::main() {
  if (!paused) {
    world.update();

    int remainingAsteroids = 0;

    for (auto object : world.getObjects()) {
      if (object->getClass() == WorldObjectClass::ASTEROID) {
        remainingAsteroids++;
      }
    }

    if (remainingAsteroids == 0) {
      startWave();
      waveId++;
    }

    updateRespawnTimers();
  }
}

void GameScene::updateRespawnTimers() {
  auto it = respawnTimers.begin();

  while (it != respawnTimers.end()) {
    (**it).time--;

    if ((**it).time == 0) {
      (**it).session->setLives((**it).session->getLives() - 1);

      if ((**it).session->getLives() == 0) {
        onGameOver((**it).session);
      } else {
        (**it).session->spawnShip(&world);
      }

//      it = respawnTimers.erase(it);
    } else {
      ++it;
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
  if (getRemainingPlayerCount() == 0) {
    world.clear();
    game->setScene(new GameOverScene(game));
  }
}

void GameScene::onShipDestroyed(PlayerSession *playerSession) {
  playerSession->getPlayer()->getController()->setDelegate(nullptr);
  startRespawnTimer(playerSession);
}

void GameScene::startRespawnTimer(PlayerSession *playerSession) {
  respawnTimers.push_back(std::make_unique<respawn_timer_t>(respawn_timer_t{
      session: playerSession,
      time: RESPAWN_TIME
  }));
}

int GameScene::getRemainingPlayerCount() {
  int count = 0;

  for (const auto &session : *game->getSessions())
    if (session->getLives() > 0)
      count++;

  return count;
}

void GameScene::drawWaveBar() {

}

GameScene::GameScene(Asteroids *game) : world(game, 640, 480) {
  this->game = game;
}

GameScene::~GameScene() {
  game->getControllers().getFirst()->setDelegate(nullptr);
}
