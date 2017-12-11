#include <SFML/Window/Keyboard.hpp>
#include "KeyboardController.h"

void KeyboardController::poll() {
  for (auto &it : map) {
    if (sf::Keyboard::isKeyPressed(it.second)) {
      emit(it.first);
    }
  }
}
