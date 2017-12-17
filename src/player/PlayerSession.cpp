

#include "PlayerSession.h"

void PlayerSession::spawnShip(WorldInterface *world) {
  if (ship != nullptr) {
    delete(ship);
  }

  ship = new Ship(world, this);
  ship->pos.x = world->getWidth() / 2;
  ship->pos.y = world->getHeight() / 2;

  player->getController()->setDelegate(ship);
  world->pushObject(ship);
}
