

#include "PlayerSession.h"

void PlayerSession::spawnShip(WorldInterface *world) {
  auto ship = new Ship(world, this);
  // todo: place ship somewhere with no collisions
  ship->pos.x = 100;
  ship->pos.y = 100;

  this->ship = ship;
  player->getController()->setDelegate(ship);
  world->pushObject(ship);
}
