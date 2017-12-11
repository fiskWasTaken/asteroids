//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include <string>
#include "input/ControllerInterface.h"

class Player {
 public:
  explicit Player(const std::string &name) {
    this->name = name;
  }

  inline void setController(ControllerInterface *controller) {
    this->controller = controller;
  }

  inline ControllerInterface *getController() {
    return controller;
  }

  inline std::string getName() { return name; }

 private:
  std::string name;
  ControllerInterface *controller = nullptr;
};

#endif //ASTEROIDS_PLAYER_H
