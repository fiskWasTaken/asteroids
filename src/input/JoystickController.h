#pragma once

#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Event.hpp>
#include "IController.h"

struct axis_actions_t
{
  InputAction left;
  InputAction right;
};

struct button_state_t
{
  InputAction action = InputAction::NIL;
  bool pressed = false;
};

class JoystickController : public IController
{
private:
  unsigned int id;
  std::map<unsigned int, button_state_t> buttonMap{};
  std::map<sf::Joystick::Axis, axis_actions_t> axisMap{};
  const float DEAD_ZONE = 30.0F;

public:
  explicit JoystickController(unsigned int id)
  {
    this->id = id;
  }

  void poll() override
  {
    for (auto &it : axisMap)
    {
      float x = sf::Joystick::getAxisPosition(id, it.first);

      if (x < -DEAD_ZONE)
      {
        emit(it.second.left, false);
      }
      else if (x > DEAD_ZONE)
      {
        emit(it.second.right, false);
      }
    }

    for (auto &it : buttonMap)
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

  void assignButtonToAction(unsigned int buttonId, InputAction action)
  {
    buttonMap[buttonId] = {action, false};
  }

  void assignAxisToActions(sf::Joystick::Axis axis, axis_actions_t actions)
  {
    axisMap[axis] = actions;
  }

  bool pass(sf::Event event)
  {
    if (event.joystickButton.joystickId != id)
      return false;

    if (buttonMap.count(event.joystickButton.button) == 0)
      return false;

    if (event.type == event.JoystickButtonPressed)
    {
      buttonMap[event.joystickButton.button].pressed = true;
      emit(buttonMap[event.joystickButton.button].action, true);
      return true;
    }
    else if (event.type == event.JoystickButtonReleased)
    {
      buttonMap[event.joystickButton.button].pressed = false;
      return true;
    }

    // NB: cases have been known to fall through and cause keyboard input to be eaten
    // Thus, we return false instead of true
    return false;
  }
};
