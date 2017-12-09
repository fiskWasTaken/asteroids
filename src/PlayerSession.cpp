//
// Created by fisk on 21/09/17.
//

#include "PlayerSession.h"
#include "entities/Ship.h"
void PlayerSession::spawnShip(WorldInterface *world) {
  auto ship = new Ship(world, this);
  ship->pos.x = 200;
  ship->pos.y = 200;

  player->getController()->setDelegate(ship);
  world->pushObject(ship);
}
