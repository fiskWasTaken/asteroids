#include "JoystickController.h"
void JoystickController::poll() {
  for (auto &it: axisMap) {
    float x = sf::Joystick::getAxisPosition(id, it.first);

    if (x < 0 - DEAD_ZONE) {
      emit(it.second.left);
    } else if (x > 0 + DEAD_ZONE) {
      emit(it.second.right);
    }
  }

  for (auto &it : buttonMap) {
    if (sf::Joystick::isButtonPressed(id, it.first)) {
      emit(it.second);
    }
  }
}

std::string JoystickController::getKeyString(InputAction action) {
  auto button = buttonMap[action];
  return "Button"; // fuck you not done yet
}
