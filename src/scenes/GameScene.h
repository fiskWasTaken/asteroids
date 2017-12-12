#pragma once

#include <Asteroids.h>
#include "SceneInterface.h"

class GameScene : public SceneInterface, public ControllerListenerInterface {
 private:
  const int RESPAWN_TIME = 50;
  const int LEVEL_TEXT_DISPLAY_TIME = 100;

  sf::Time lastFrameTime;
  sf::Clock clock;

  Asteroids *game;
  World *world;
  std::map<PlayerSession *, int> respawnTimers;
  PlayerSession *pauseInitiator = nullptr;
  bool paused = false;
  int showLevelTextTimeout = 0;

  void onGameOver(PlayerSession *playerSession);
  void startRespawnTimer(PlayerSession *playerSession);

 public:
  explicit GameScene(Asteroids *game) {
    this->game = game;
    world = new World(game, 640, 480);
    clock = sf::Clock();
    lastFrameTime = clock.getElapsedTime();
  }

  void handleEvents() override;
  void render(RendererInterface *renderer) override;
  void onVisible() override;
  void onAction(InputAction action) override;

  void pause(PlayerSession *initiator);

  void drawHud(RendererInterface *renderer);
  void drawWorld(RendererInterface *renderer);

  void main() override;
  void onShipDestroyed(PlayerSession *playerSession);
  void drawDebug(RendererInterface *renderer);

  ~GameScene() override {
    delete world;
  }
  void loadCurrentLevel();

  void updateRespawnTimers();
  void drawTimings(RendererInterface *pInterface);
};
