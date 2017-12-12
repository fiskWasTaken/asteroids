#pragma once

#include <Asteroids.h>
#include <renderer/WorldRenderer.h>
#include "SceneInterface.h"

class GameScene : public SceneInterface, public ControllerListenerInterface {
 private:
  const int RESPAWN_TIME = 50;
  const int LEVEL_TEXT_DISPLAY_TIME = 100;

  Asteroids *game;
  World *world;
  std::map<PlayerSession *, int> respawnTimers;
  PlayerSession *pauseInitiator = nullptr;
  WorldRenderer worldRenderer;

  bool paused = false;
  int showLevelTextTimeout = 0;

  void onGameOver(PlayerSession *playerSession);
  void startRespawnTimer(PlayerSession *playerSession);

 public:
  explicit GameScene(Asteroids *game) {
    this->game = game;
    world = new World(game, 640, 480);
  }

  void handleEvents() override;
  void render(WindowRendererInterface *renderer) override;
  void onVisible() override;
  void onAction(InputAction action) override;

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
