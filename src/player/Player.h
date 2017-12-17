#pragma once

#include <string>
#include "input/ControllerInterface.h"

class Player {
 public:
  explicit Player(const std::string &name) {
    this->name = name;
  }

  void setController(ControllerInterface *controller) {
    this->controller = controller;
  }

  ControllerInterface *getController() {
    return controller;
  }

  std::string getName() { return name; }

  sf::Color getColor() { return this->color; }
  void setColor(sf::Color color) { this->color = color; }

 private:
  sf::Color color = sf::Color(212, 66, 244);
  std::string name;
  ControllerInterface *controller = nullptr;
};