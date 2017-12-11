//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H

#include "AbstractWorldObject.h"
#include "../Player.h"

class PlayerSession;

class Ship : public AbstractWorldObject, public ControllerListenerInterface {
 private:
  PlayerSession *playerSession;
  float maxSpeed = 5.0F;
  float maxRotateSpeed = 5.0F;
  int fireRate = 10;
  int fireCooldown = 0;
  bool isFiring = false;
  bool isDestroyed = false;

 public:
  WorldObjectClass getClass() override {
    return WorldObjectClass::SHIP;
  }

  explicit Ship(WorldInterface *world, PlayerSession *playerSession) : AbstractWorldObject(world) {
    this->playerSession = playerSession;

    points.emplace_back(20, 10);
    points.emplace_back(0, 0);
    points.emplace_back(0, 20);
    origin = sf::Vector2f(10, 10);
  }

  void onAction(InputAction action) override;
  void update() override;
  bool isRecyclable() override;

  void onDestroyed();

  void renderTo(sf::RenderWindow *renderWindow) override;
};

#endif //ASTEROIDS_SHIP_H
