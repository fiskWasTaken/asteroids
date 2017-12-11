

#include "PlayerSession.h"

void PlayerSession::spawnShip(WorldInterface *world) {
  ship = new Ship(world, this);
  // todo: place ship somewhere with no collisions
  ship->pos.x = 100;
  ship->pos.y = 100;

  player->getController()->setDelegate(ship);
  world->pushObject(ship);
}
