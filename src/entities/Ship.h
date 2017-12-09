//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H

#include "AbstractWorldObject.h"
#include "../Player.h"
#include "../PlayerSession.h"

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

  explicit Ship(World *world, PlayerSession *playerSession) : AbstractWorldObject(world) {
    this->playerSession = playerSession;

    points.push_back(sf::Vector2f(20, 10));
    points.push_back(sf::Vector2f(0, 0));
    points.push_back(sf::Vector2f(0, 20));
  }

  void onAction(InputAction action) override;
  void update() override;
  void limitSpeed();
  float getSpeed();
  bool isRecyclable() override;

  sf::Drawable *getDrawable() override;
  void onDestroyed();
};

#endif //ASTEROIDS_SHIP_H
