#pragma once

#include <entities/Ship.h>
#include "Player.h"
#include "world/World.h"

class Ship;

class PlayerSession {
 private:
  Ship *ship = nullptr;
  Player *player;
  int score;
  int lives;

 public:
  explicit PlayerSession(Player *player, int lives = 1) {
    this->player = player;
    this->lives = lives;
    this->score = 0;
  }

  Player *getPlayer() const { return player; }

  int getScore() const { return score; }
  void setScore(int score) { this->score = score; }

  int getLives() const { return lives; }
  void setLives(int lives) { this->lives = lives; }

  Ship *getShip() {
    return ship;
  }

  void spawnShip(WorldInterface *world);
};