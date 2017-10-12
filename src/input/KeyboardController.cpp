//
// Created by Fisk on 09/10/2017.
//

#include <SFML/Window/Keyboard.hpp>
#include "KeyboardController.h"

void KeyboardController::poll() {
  if (sf::Keyboard::isKeyPressed(map[InputAction::LEFT])) {
    // Left
    emit(InputAction::LEFT);
  }

  if (sf::Keyboard::isKeyPressed(map[InputAction::RIGHT])) {
    // Right
    emit(InputAction::RIGHT);
  }

  if (sf::Keyboard::isKeyPressed(map[InputAction::ACCELERATE])) {
    // Accelerate
    emit(InputAction::ACCELERATE);
  }

  if (sf::Keyboard::isKeyPressed(map[InputAction::BRAKE])) {
    // Brake
    emit(InputAction::BRAKE);
  }

  if (sf::Keyboard::isKeyPressed(map[InputAction::FIRE])) {
    // Fire
    emit(InputAction::FIRE);
  }
}
