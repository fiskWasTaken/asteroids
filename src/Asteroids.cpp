//
// Created by fisk on 24/09/17.
//

#include "Asteroids.h"
#include "input/KeyboardController.h"
void Asteroids::main() {
//  printf("GameInterface is running... (tick %ld)\n", tick);
  world->update();
}

Controller *Asteroids::getDefaultController() {
  auto controller = new KeyboardController();
  controller->assignKeyForAction(InputAction::ACCELERATE, sf::Keyboard::W);
  controller->assignKeyForAction(InputAction::BRAKE, sf::Keyboard::S);
  controller->assignKeyForAction(InputAction::LEFT, sf::Keyboard::A);
  controller->assignKeyForAction(InputAction::RIGHT, sf::Keyboard::D);
  controller->assignKeyForAction(InputAction::FIRE, sf::Keyboard::C);
  controller->assignKeyForAction(InputAction::ALTFIRE, sf::Keyboard::L);
  controller->assignKeyForAction(InputAction::PANIC, sf::Keyboard::K);
  controller->assignKeyForAction(InputAction::PAUSE, sf::Keyboard::P);

  return controller;
}