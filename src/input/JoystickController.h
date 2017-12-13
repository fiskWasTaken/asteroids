#pragma once

#include <SFML/Window/Joystick.hpp>
#include "ControllerInterface.h"

struct axis_actions_t {
  InputAction left;
  InputAction right;
};

class JoystickController : public ControllerInterface {
 private:
  unsigned int id;
  std::map<unsigned int, InputAction> buttonMap{};
  std::map<sf::Joystick::Axis, axis_actions_t> axisMap{};
  const float DEAD_ZONE = 30.0F;

 public:
  explicit JoystickController(unsigned int id) {
    this->id = id;
  }

  void poll() override;
  std::string getKeyString(InputAction action) override;

  void assignButtonToAction(unsigned int buttonId, InputAction action) {
    buttonMap[buttonId] = action;
  }

  void assignAxisToActions(sf::Joystick::Axis axis, axis_actions_t actions) {
    axisMap[axis] = actions;
  }
};


