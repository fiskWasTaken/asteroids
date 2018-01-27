#pragma once

#include <Asteroids.h>
#include <renderer/WorldRenderer.h>
#include <waves/WaveGenerator.h>
#include "SceneInterface.h"
#include <SFML/Graphics/Shader.hpp>

struct respawn_timer_t {
  PlayerSession *session;
  int time;
};

class GameScene : public SceneInterface, public ControllerListenerInterface {
 private:
  const int BASE_WAVE_INTERVAL_TIME = 1000;
  const int RESPAWN_TIME = 50;

  Asteroids *game;
  World world;
  std::vector<std::unique_ptr<respawn_timer_t>> respawnTimers;
  PlayerSession *pauseInitiator = nullptr;
  WorldRenderer worldRenderer;
  WaveGenerator waveGenerator;
  sf::Shader shader;
  sf::Clock clock;

  int waveTimer = 0;
  int waveId = 0;

  bool paused = false;

  void startRespawnTimer(PlayerSession *playerSession);

 public:
  explicit GameScene(Asteroids *game);
  ~GameScene() override;

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
  void drawWaveBar(WindowRendererInterface *renderer);
};
