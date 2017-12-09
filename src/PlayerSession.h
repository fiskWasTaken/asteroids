//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_PLAYERSESSION_H
#define ASTEROIDS_PLAYERSESSION_H

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
  explicit PlayerSession(Player *player, int lives = 5) {
    this->player = player;
    this->lives = lives;
    this->score = 0;
  }

  inline Player *getPlayer() const { return player; }

  inline int getScore() const { return score; }
  inline void setScore(int score) { PlayerSession::score = score; }

  inline int getLives() const { return lives; }
  inline void setLives(int lives) { this->lives = lives; }

  inline Ship *getShip() {
    return this->ship;
  }

  void spawnShip(WorldInterface *world);
};

#endif //ASTEROIDS_PLAYERSESSION_H
