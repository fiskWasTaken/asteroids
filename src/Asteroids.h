#pragma once

#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <input/ControllerManager.h>
#include <input/presets.h>
#include "GameInterface.h"
#include "player/PlayerSession.h"

class Asteroids : public GameInterface {
 private:
  std::vector<std::shared_ptr<PlayerSession>> *sessions;
  ControllerManager controllerManager;

 public:
  Asteroids();

  std::vector<std::shared_ptr<PlayerSession>> *getSessions() { return sessions; }

  void main() override;
  ControllerManager &getControllers();
};
