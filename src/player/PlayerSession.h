#pragma once

#include <entities/Ship.h>
#include "Player.h"
#include "world/World.h"

class Ship;

struct PlayerSession
{
  Ship *ship = nullptr;
  Player *player;
  int score = 0;
  int lives = 0;

  PlayerSession(Player *player, int lives = 5)
  {
    this->player = player;
    this->lives = lives;
  }

  void spawnShip(WorldInterface *world)
  {
    // NB: we do not care about the previous ship reference if there is one. it gets
    // deleted by the world garbage collector routine and not handled here.
    ship = new Ship(world, this);
    ship->pos.x = world->getWidth() / 2;
    ship->pos.y = world->getHeight() / 2;
    ship->color = player->getColor();

    player->getController()->setDelegate(ship);
    world->push(ship);
  }
};