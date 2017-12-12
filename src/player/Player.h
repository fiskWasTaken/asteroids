#pragma once

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

  inline sf::Color getColor() { return this->color; }
  inline void setColor(sf::Color color) { this->color = color; }

 private:
  sf::Color color = sf::Color(58, 163, 67);
  std::string name;
  ControllerInterface *controller = nullptr;
};