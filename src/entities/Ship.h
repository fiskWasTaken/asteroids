//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H

#include "WorldObject.h"
#include "Player.h"

class Ship : WorldObject {
 private:
  Player *player;

 public:
  static const WorldObjectClass OBJECT_CLASS = WorldObjectClass::SHIP;

  Ship(Player *player) {
    this->player = player;
  }
};

#endif //ASTEROIDS_SHIP_H
