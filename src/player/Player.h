#pragma once

#include <string>
#include "input/IController.h"

class Player {
 private:
  sf::Color color = sf::Color(212, 66, 244);
  std::string name;
  IController *controller = nullptr;

 public:
  explicit Player(const std::string &name) {
    this->name = name;
  }

  void setController(IController *controller) { this->controller = controller; }
  void setColor(sf::Color color) { this->color = color; }
  IController *getController() { return controller; }
  std::string getName() { return name; }
  sf::Color getColor() { return this->color; }
};