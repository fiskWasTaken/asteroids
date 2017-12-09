//
// Created by fisk on 21/09/17.
//

#include "PlayerSession.h"

void PlayerSession::spawnShip(WorldInterface *world) {
  auto ship = new Ship(world, this);
  ship->pos.x = 200;
  ship->pos.y = 200;

  this->ship = ship;
  player->getController()->setDelegate(ship);
  world->pushObject(ship);
}
