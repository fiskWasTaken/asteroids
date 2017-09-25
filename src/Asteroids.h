//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_ASTEROIDS_H
#define ASTEROIDS_ASTEROIDS_H

#include <vector>
#include "Game.h"
#include "PlayerSession.h"
class Asteroids : public Game {
 private:
  World *world;
  std::vector<PlayerSession*> *sessions;

 public:
  inline Asteroids(): Game() {
    world = new World(512, 512);
    sessions = new std::vector<PlayerSession*>();
  }

  inline World *getWorld() const {
    return world;
  }

  inline std::vector<PlayerSession*> *getSessions() const {
    return sessions;
  }

  void main();
};

#endif //ASTEROIDS_ASTEROIDS_H
