//
// Created by fisk on 24/09/17.
//

#include "Asteroids.h"
#include "input/KeyboardController.h"
void Asteroids::main() {
//  printf("Game is running... (tick %ld)\n", tick);
  world->update();
}

Controller *Asteroids::getDefaultController() {
  auto controller = new KeyboardController();
  controller->assignKeyForAction(InputAction::ACCELERATE, sf::Keyboard::W);
  controller->assignKeyForAction(InputAction::BRAKE, sf::Keyboard::S);
  controller->assignKeyForAction(InputAction::LEFT, sf::Keyboard::A);
  controller->assignKeyForAction(InputAction::RIGHT, sf::Keyboard::D);
  controller->assignKeyForAction(InputAction::FIRE, sf::Keyboard::C);

  return controller;
}
