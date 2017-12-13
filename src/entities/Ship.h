#pragma once

#include "AbstractWorldObject.h"
#include "player/Player.h"

class PlayerSession;

class Ship : public AbstractWorldObject, public ControllerListenerInterface {
 private:
  const float MAX_SPEED = 3.0F;
  const float MAX_ROTATE_SPEED = 5.0F;
  const int FIRE_RATE = 10;

  PlayerSession *playerSession;
  int fireCooldown = 0;
  bool isFiring = false;
  bool isFiringAltWeapon;
  bool isThrusting = false;
  int invincibilityTimer = 100; // initial invincibility time on spawn in frames

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

  void onDestroyed();

  void renderTo(sf::RenderWindow *renderWindow) override;

  inline PlayerSession *getPlayerSession() {
    return playerSession;
  }
  void fireBullet();
  void onCollision(AbstractWorldObject *other);
  void onShipHit(Ship *other);
  void renderThruster(sf::RenderWindow *renderWindow);
  void renderShip(sf::RenderWindow *renderWindow);

  inline bool isOnInvincibilityCooldown() {
    return invincibilityTimer > 0;
  }

  inline void setInvincibilityCooldown(int cooldown) {
    invincibilityTimer = cooldown;
  }

};