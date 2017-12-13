#include <input/JoystickController.h>
#include "Asteroids.h"
#include "input/KeyboardController.h"
void Asteroids::main() {
//  printf("GameInterface is running... (tick %ld)\n", tick);
  scene->main();
  tick += 1;
}

ControllerInterface *Asteroids::getDefaultKeyboardController() {
  auto controller = new KeyboardController();
  controller->assignKeyToAction(InputAction::ACCELERATE, sf::Keyboard::W);
  controller->assignKeyToAction(InputAction::BRAKE, sf::Keyboard::S);
  controller->assignKeyToAction(InputAction::LEFT, sf::Keyboard::A);
  controller->assignKeyToAction(InputAction::RIGHT, sf::Keyboard::D);
  controller->assignKeyToAction(InputAction::FIRE, sf::Keyboard::LShift);
  controller->assignKeyToAction(InputAction::ALTFIRE, sf::Keyboard::Space);
  controller->assignKeyToAction(InputAction::PANIC, sf::Keyboard::K);
  controller->assignKeyToAction(InputAction::PAUSE, sf::Keyboard::P);

  return controller;
}

ControllerInterface *Asteroids::getDefaultJoystickController() {
  auto controller = new JoystickController(0);
  controller->assignAxisToActions(sf::Joystick::Axis::X, {
      InputAction::LEFT,
      InputAction::RIGHT
  });

  controller->assignAxisToActions(sf::Joystick::Axis::Z, {
      InputAction::NIL,
      InputAction::BRAKE
  });

  controller->assignAxisToActions(sf::Joystick::Axis::R, {
      InputAction::NIL,
      InputAction::ACCELERATE
  });

  // Mappings are typical of an Xbox (360/One) controller
  // Button 0: A
  controller->assignButtonToAction(0, InputAction::FIRE);
  // Button 1: B
  // Button 2: X
  controller->assignButtonToAction(2, InputAction::ALTFIRE);
  // Button 3: Y
  controller->assignButtonToAction(3, InputAction::PANIC);
  // Button 4: LB
  // Button 5: RB
  // Button 6: Back/Share/Menu/Select/etc
  // Button 7: Start
  controller->assignButtonToAction(7, InputAction::PAUSE);

  return controller;
}

Playlist &Asteroids::getPlaylist() {
  return playlist;
}
