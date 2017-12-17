#include "Asteroids.h"

void Asteroids::main() {
  scene->main();
  tick += 1;
}

ControllerManager &Asteroids::getControllers() {
  return controllerManager;
}
