#pragma once

#include "ControllerInterface.h"
#include "ControllerListenerInterface.h"

class KeyboardController : public ControllerInterface {
 private:
  std::map<InputAction, sf::Keyboard::Key> map{};

 public:
  void poll() override;
  std::string getKeyString(InputAction action) override;

  void assignKeyToAction(InputAction action, sf::Keyboard::Key key) {
    map[action] = key;
  }
};