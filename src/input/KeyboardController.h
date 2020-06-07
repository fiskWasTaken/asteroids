#pragma once

#include <SFML/Window/Event.hpp>
#include "IController.h"
#include "IControllerListener.h"

struct key_state_t
{
  InputAction action = InputAction::NIL;
  bool pressed = false;
};

class KeyboardController : public IController
{
private:
  std::map<sf::Keyboard::Key, key_state_t> map{};

public:
  void poll() override
  {
    for (auto &it : map)
    {
      if (it.second.pressed)
      {
        emit(it.second.action, false);
      }
    }
  }
  
  std::string getKeyString(InputAction action) override
  {
    // todo
    return "[NOT BOUND]";
  }

  void bind(InputAction action, sf::Keyboard::Key key)
  {
    map[key] = {action, false};
  }

  bool pass(sf::Event event) override
  {
    if (map.count(event.key.code) == 0)
      return false;

    if (event.type == event.KeyPressed && !map[event.key.code].pressed)
    {
      map[event.key.code].pressed = true;
      emit(map[event.key.code].action, true);
    }
    else if (event.type == event.KeyReleased)
    {
      map[event.key.code].pressed = false;
    }

    return true;
  }
};