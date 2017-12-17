#pragma once

#include <Asteroids.h>
#include <renderer/WorldRenderer.h>
#include <waves/WaveGenerator.h>
#include "SceneInterface.h"

struct respawn_timer_t {
  PlayerSession *session;
  int time;
};

class GameScene : public SceneInterface, public ControllerListenerInterface {
 private:
  const int BASE_WAVE_INTERVAL_TIME = 1000;
  const int RESPAWN_TIME = 50;
  const int WAVE_TEXT_DISPLAY_TIME = 100;

  Asteroids *game;
  World world;
  std::vector<std::unique_ptr<respawn_timer_t>> respawnTimers;
  PlayerSession *pauseInitiator = nullptr;
  WorldRenderer worldRenderer;

  WaveGenerator waveGenerator;

  int waveTimer = 0;
  int waveId = 1;

  bool paused = false;
  int showWaveTextTimeout = 0;

  void onGameOver(PlayerSession *playerSession);
  void startRespawnTimer(PlayerSession *playerSession);

 public:
  explicit GameScene(Asteroids *game) : world(game, 640, 480) {
    this->game = game;
  }

  void render(WindowRendererInterface *renderer) override;
  void onVisible() override;
  void onAction(InputAction action, bool once) override;

  void pause(PlayerSession *initiator);

  void drawHud(WindowRendererInterface *renderer);

  void main() override;
  void onShipDestroyed(PlayerSession *playerSession);

  void startWave();

  void updateRespawnTimers();
  int getRemainingPlayerCount();

  ~GameScene() override {
    game->getControllers().getFirst()->setDelegate(nullptr);
  }
};
