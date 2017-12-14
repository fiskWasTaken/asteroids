#pragma once

#include <SFML/Window/Event.hpp>
#include "ControllerInterface.h"
#include "ControllerListenerInterface.h"

struct key_state_t {
  InputAction action = InputAction::NIL;
  bool pressed = false;
};

class KeyboardController : public ControllerInterface {
 private:
  std::map<sf::Keyboard::Key, key_state_t> map{};

 public:
  void poll() override;
  std::string getKeyString(InputAction action) override;

  void assignKeyToAction(InputAction action, sf::Keyboard::Key key) {
    map[key] = {action, false};
  }

  bool pass(sf::Event event) override;
};