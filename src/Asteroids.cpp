#include "Asteroids.h"

void Asteroids::main() {
  scene->main();
  tick += 1;
}

ControllerManager &Asteroids::getControllers() {
  return controllerManager;
}
Asteroids::Asteroids() : GameInterface() {
  // update() needs to be called as this is instantiated before the window
  sf::Joystick::update();

  for (unsigned int i = 0; i < 8; i++) {
    if (sf::Joystick::isConnected(i)) {
      controllerManager.registerController("j" + std::to_string(i), presets::getDefaultJoystickController(i));
    }
  }

  controllerManager.registerController("k0", presets::getDefaultK0Controller());
  controllerManager.registerController("k1", presets::getDefaultK1Controller());
  sessions = new std::vector<std::shared_ptr<PlayerSession>>();
}
