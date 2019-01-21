

#include "PlayerSession.h"

void PlayerSession::spawnShip(WorldInterface *world) {
  // we do not care if a ship reference already exists; it may be a stale one.

  ship = new Ship(world, this);
  ship->pos.x = world->getWidth() / 2;
  ship->pos.y = world->getHeight() / 2;

  player->getController()->setDelegate(ship);
  world->push(ship);
}
