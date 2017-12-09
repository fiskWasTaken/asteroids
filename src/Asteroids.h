//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_ASTEROIDS_H
#define ASTEROIDS_ASTEROIDS_H

#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include "Game.h"
#include "PlayerSession.h"
#include "HighScores.h"

class Game;

class Asteroids : public Game {
 private:
  World *world;
  std::vector<PlayerSession*> *sessions;
  HighScores highScores;

 public:
  inline Asteroids(): Game() {
    world = new World(640, 480);
    sessions = new std::vector<PlayerSession*>();
  }

  inline World *getWorld() const {
    return world;
  }

  inline std::vector<PlayerSession*> *getSessions() const {
    return sessions;
  }

  void main() override;

  inline HighScores getHighScores() const {
    return highScores;
  }

  Controller *getDefaultController();
};

#endif //ASTEROIDS_ASTEROIDS_H
