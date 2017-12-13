#include <input/JoystickController.h>
#include "Asteroids.h"
#include "input/KeyboardController.h"
void Asteroids::main() {
//  printf("GameInterface is running... (tick %ld)\n", tick);
  scene->main();
  tick += 1;
}

Playlist &Asteroids::getPlaylist() {
  return playlist;
}

ControllerManager &Asteroids::getControllers() {
  return controllerManager;
}
