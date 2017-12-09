//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_SCENES_GAMESCENE_H
#define ASTEROIDS_SCENES_GAMESCENE_H

#include <Asteroids.h>
#include "SceneInterface.h"


class GameScene : public SceneInterface, public ControllerListenerInterface {
 private:
  Asteroids *game;
  World *world;
  std::map<PlayerSession*, int> respawnTimers;
  PlayerSession *pauseInitiator = nullptr;
  const int respawnTime = 50;
  bool paused = false;

  void onGameOver(PlayerSession *playerSession);
  void startRespawnTimer(PlayerSession *playerSession);

 public:
  explicit GameScene(Asteroids *game) {
    this->game = game;
    world = new World(game, 640, 480);
  }
  void handleEvents() override;
  void render(RendererInterface *renderer) override;
  void onVisible() override;
  void onDestroy() override;
  void onAction(InputAction action) override;

  void pause(PlayerSession *initiator);

  void drawHud(RendererInterface *renderer);
  void drawWorld(RendererInterface *renderer);

  void main() override;
  void onShipDestroyed(PlayerSession *playerSession);
};

#endif //ASTEROIDS_SCENES_GAMESCENE_H
