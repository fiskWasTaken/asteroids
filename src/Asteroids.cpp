//
// Created by fisk on 24/09/17.
//

#include "Asteroids.h"
void Asteroids::main() {
  printf("Game is running... (tick %ld)\n", tick);
  world->update();
}