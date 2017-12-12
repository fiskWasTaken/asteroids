#pragma once

#include "ControllerInterface.h"
#include "ControllerListenerInterface.h"

class KeyboardController : public ControllerInterface {
 private:
  std::map<InputAction, sf::Keyboard::Key> map{};

 public:
  void poll() override;
  void assignKeyForAction(InputAction action, sf::Keyboard::Key key) {
    map[action] = key;
  }

  std::string getKeyString(InputAction action) override;
};