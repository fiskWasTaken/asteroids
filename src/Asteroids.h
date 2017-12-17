#pragma once

#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <levels/Playlist.h>
#include <input/ControllerManager.h>
#include <input/presets.h>
#include "GameInterface.h"
#include "player/PlayerSession.h"

class Asteroids : public GameInterface {
 private:
  std::vector<std::shared_ptr<PlayerSession>> *sessions;
  Playlist playlist;
  ControllerManager controllerManager;

 public:
  Asteroids() : GameInterface() {
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

  std::vector<std::shared_ptr<PlayerSession>> *getSessions() {
    return sessions;
  }

  void main() override;

  Playlist &getPlaylist();
  ControllerManager &getControllers();
};
