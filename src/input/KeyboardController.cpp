#include <SFML/Window/Keyboard.hpp>
#include "KeyboardController.h"

void KeyboardController::poll() {
  for (auto &it : map) {
    if (sf::Keyboard::isKeyPressed(it.second)) {
      emit(it.first);
    }
  }
}

std::string KeyboardController::getKeyString(InputAction action) {
  auto key = map[action];

  if (key == sf::Keyboard::Key::LShift) {
    return "Shift";
  }

  char letter = 'A' + map[action];
  return std::string({letter});
}
