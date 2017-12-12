#pragma once

#include "AbstractWorldObject.h"
#include "player/Player.h"

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

    points.emplace_back(20, 8);
    points.emplace_back(0, 0);
    points.emplace_back(0, 3);
    points.emplace_back(2, 3);
    points.emplace_back(2, 5);
    points.emplace_back(0, 5);
    points.emplace_back(0, 11);
    points.emplace_back(2, 11);
    points.emplace_back(2, 13);
    points.emplace_back(0, 13);
    points.emplace_back(0, 16);

    origin = sf::Vector2f(10, 8);

  }

  void onAction(InputAction action) override;
  void update() override;
  bool isRecyclable() override;

  void onDestroyed();

  void renderTo(sf::RenderWindow *renderWindow) override;

  inline PlayerSession *getPlayerSession() {
    return playerSession;
  }
  void fireBullet();
  void onCollision(AbstractWorldObject *other);
  void onShipHit(Ship *other);
};