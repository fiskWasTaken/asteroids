//
// Created by Fisk on 09/10/2017.
//

#ifndef ASTEROIDS_KEYBOARDCONTROLLER_H
#define ASTEROIDS_KEYBOARDCONTROLLER_H

#include <set>
#include "Controller.h"
#include "ControllerListenerInterface.h"
class KeyboardController: public Controller {
 private:
  std::map<InputAction, sf::Keyboard::Key> map;

 public:
  void poll();
  void assignKeyForAction(InputAction action, sf::Keyboard::Key key) {
    map[action] = key;
  }
};

#endif //ASTEROIDS_KEYBOARDCONTROLLER_H
