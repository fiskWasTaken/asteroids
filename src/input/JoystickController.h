#pragma once

#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Event.hpp>
#include "ControllerInterface.h"

struct axis_actions_t {
  InputAction left;
  InputAction right;
};

struct button_state_t {
  InputAction action = InputAction::NIL;
  bool pressed = false;
};

class JoystickController : public ControllerInterface {
 private:
  unsigned int id;
  std::map<unsigned int, button_state_t> buttonMap{};
  std::map<sf::Joystick::Axis, axis_actions_t> axisMap{};
  const float DEAD_ZONE = 30.0F;

 public:
  explicit JoystickController(unsigned int id) {
    this->id = id;
  }

  void poll() override;
  std::string getKeyString(InputAction action) override;

  void assignButtonToAction(unsigned int buttonId, InputAction action);

  void assignAxisToActions(sf::Joystick::Axis axis, axis_actions_t actions) {
    axisMap[axis] = actions;
  }

  bool pass(sf::Event event) override;
};


