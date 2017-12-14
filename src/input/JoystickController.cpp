#include <SFML/Window/Event.hpp>
#include "JoystickController.h"

void JoystickController::poll() {
  for (auto &it: axisMap) {
    float x = sf::Joystick::getAxisPosition(id, it.first);

    if (x < 0 - DEAD_ZONE) {
      emit(it.second.left, false);
    } else if (x > 0 + DEAD_ZONE) {
      emit(it.second.right, false);
    }
  }

  for (auto &it : buttonMap) {
    if (it.second.pressed) {
      emit(it.second.action, false);
    }
  }
}

std::string JoystickController::getKeyString(InputAction action) {
  // todo
  return "[NOT BOUND]";
}

bool JoystickController::pass(sf::Event event) {
  if (event.joystickButton.joystickId != id)
    return false;

  if (buttonMap.count(event.joystickButton.button) == 0)
    return false;

  if (event.type == event.JoystickButtonPressed) {
    buttonMap[event.joystickButton.button].pressed = true;
    emit(buttonMap[event.joystickButton.button].action, true);
  } else if (event.type == event.JoystickButtonReleased) {
    buttonMap[event.joystickButton.button].pressed = false;
  }

  return true;
}
