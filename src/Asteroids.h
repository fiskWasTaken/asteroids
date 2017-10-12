//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_ASTEROIDS_H
#define ASTEROIDS_ASTEROIDS_H

#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"
#include "PlayerSession.h"

class Game;

class Asteroids : public Game {
 private:
  World *world;
  std::vector<PlayerSession*> *sessions;

 public:
  inline Asteroids(): Game() {
    world = new World(800, 600);
    sessions = new std::vector<PlayerSession*>();
  }

  inline World *getWorld() const {
    return world;
  }

  inline std::vector<PlayerSession*> *getSessions() const {
    return sessions;
  }

  void main() override;

  Controller *getDefaultController();
};

#endif //ASTEROIDS_ASTEROIDS_H
