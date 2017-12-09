//
// Created by Fisk on 09/10/2017.
//

#include <SFML/Window/Keyboard.hpp>
#include "KeyboardController.h"

void KeyboardController::poll() {
  InputAction keys[] = {
      InputAction::ALTFIRE,
      InputAction::PANIC,
      InputAction::PAUSE,
      InputAction::LEFT,
      InputAction::RIGHT,
      InputAction::ACCELERATE,
      InputAction::BRAKE,
      InputAction::FIRE,
  };

  for (auto key : keys) {
    if (sf::Keyboard::isKeyPressed(map[key])) {
      emit(key);
    }
  }
}
