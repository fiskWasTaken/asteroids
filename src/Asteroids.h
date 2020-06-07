#pragma once

#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <input/presets.h>
#include "IGame.h"

#include <scenes/SplashScene.h>
#include <scenes/MainMenuScene.h>

class Asteroids : public IGame
{
public:
  Asteroids() : IGame()
  {
    // update() needs to be called as this is instantiated before the window
    sf::Joystick::update();

    for (unsigned int i = 0; i < 8; i++)
    {
      if (sf::Joystick::isConnected(i))
      {
        controllers.connect("j" + std::to_string(i), presets::defaultJoystick(i));
      }
    }

    controllers.connect("k0", presets::defaultK0());
    controllers.connect("k1", presets::defaultK1());

    setScene(new SplashScene(this));
  }

  void main() override
  {
    scene->main();
    tick += 1;
  }
};
