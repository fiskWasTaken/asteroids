#include "Asteroids.h"

void Asteroids::main() {
  scene->main();
  tick += 1;
}

Playlist &Asteroids::getPlaylist() {
  return playlist;
}

ControllerManager &Asteroids::getControllers() {
  return controllerManager;
}
