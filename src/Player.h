//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include <string>
#include "input/Controller.h"

class Player {
 public:
  Player(const std::string name) {
    this->name = name;
  }

  inline void setController(Controller *controller) {
    this->controller = controller;
  }

  inline Controller *getController() {
    return controller;
  }

  inline std::string getName() { return name; }

 private:
  std::string name;
  Controller *controller;
};

#endif //ASTEROIDS_PLAYER_H
