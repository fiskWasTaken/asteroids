//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include "World.h"
class Game {
 protected:
  long tick;
  bool running = false;

 public:
  void run();
  void stop();

  // methods for game instance to implement
  virtual void main() = 0;
};

#endif //ASTEROIDS_GAME_H
