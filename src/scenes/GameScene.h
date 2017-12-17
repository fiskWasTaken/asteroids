#pragma once

#include <Asteroids.h>
#include <renderer/WorldRenderer.h>
#include "SceneInterface.h"

class GameScene : public SceneInterface, public ControllerListenerInterface {
 private:
  const int BASE_WAVE_INTERVAL_TIME = 1000;
  const int RESPAWN_TIME = 50;
  const int LEVEL_TEXT_DISPLAY_TIME = 100;

  Asteroids *game;
  World *world;
  std::map<PlayerSession *, int> respawnTimers;
  PlayerSession *pauseInitiator = nullptr;
  WorldRenderer worldRenderer;

  int waveTimer = 0;

  bool paused = false;
  int showLevelTextTimeout = 0;

  void onGameOver(PlayerSession *playerSession);
  void startRespawnTimer(PlayerSession *playerSession);

 public:
  explicit GameScene(Asteroids *game) {
    this->game = game;
    world = new World(game, 640, 480);
  }

  void render(WindowRendererInterface *renderer) override;
  void onVisible() override;
  void onAction(InputAction action, bool once) override;

  void pause(PlayerSession *initiator);

  void drawHud(WindowRendererInterface *renderer);

  void main() override;
  void onShipDestroyed(PlayerSession *playerSession);

  ~GameScene() override {
    delete world;
  }
  void loadCurrentLevel();

  void updateRespawnTimers();
  int getRemainingPlayerCount();
};
