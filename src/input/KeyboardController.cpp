#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "KeyboardController.h"

void KeyboardController::poll() {
  for (auto &it : map) {
    if (it.second.pressed) {
      emit(it.second.action, false);
    }
  }
}

std::string KeyboardController::getKeyString(InputAction action) {
  // todo
  return "[NOT BOUND]";
}

bool KeyboardController::pass(sf::Event event) {
  if (map.count(event.key.code) == 0)
    return false;

  if (event.type == event.KeyPressed && !map[event.key.code].pressed) {
    map[event.key.code].pressed = true;
    emit(map[event.key.code].action, true);
  } else if (event.type == event.KeyReleased) {
    map[event.key.code].pressed = false;
  }

  return true;
}
void KeyboardController::assignKeyToAction(InputAction action, sf::Keyboard::Key key) {
  map[key] = {action, false};
}
