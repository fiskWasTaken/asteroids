//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H

#include "WorldObject.h"
#include "../Player.h"

class Ship : public WorldObject, public ControllerListenerInterface {
 private:
  Player *player;
  float maxSpeed = 5.0F;
  float maxRotateSpeed = 5.0F;
  bool isFiring = false;

 public:
  static const WorldObjectClass OBJECT_CLASS = WorldObjectClass::SHIP;

  Ship(Player *player) {
    this->player = player;
  }

  void onAction(InputAction action) override;
  void update(World *world) override;
  sf::Vector2f getRotationVector();
  void limitSpeed();
  float getSpeed();
  bool isRecyclable() override;
};

#endif //ASTEROIDS_SHIP_H
