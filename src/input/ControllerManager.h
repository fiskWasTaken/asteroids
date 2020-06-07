#pragma once

#include <SFML/Window/Event.hpp>
#include "IController.h"
#include "JoystickController.h"

inline std::string getJoystickKey(int id) {
  return "j" + std::to_string(id);
}

class ControllerManager
{
private:
  std::map<std::string, IController *> map;

public:
  /**
   * Register a controller
   * @param id The unique key for this controller
   * @param controller The controller
   */
  void connect(const std::string &id, IController *controller)
  {
    map[id] = controller;
  }

  /**
   * @param id
   * @return The controller identified by this key, or the best available if not found
   */
  IController *getController(std::string id)
  {
    if (map[id] == nullptr)
    {
      return getFirstAvailable();
    }

    return map[id];
  }

  std::map<std::string, IController *> getControllers()
  {
    return map;
  };

  /**
   * @return The first available controller.
   */
  IController *getFirstAvailable()
  {
    for (auto const &controller : map)
    {
      if (controller.second->getDelegate() == nullptr)
      {
        return controller.second;
      }
    }

    return nullptr;
  }

  /**
   * @return The first controller in the (nb: unsorted) map.
   * Caution: use getFirstAvailable to prevent overwriting a
   * delegate for something else using the controller.
   */
  IController *getFirst()
  {
    return map.begin()->second;
  }

  void undelegateAll()
  {
    for (auto const &controller : map)
    {
      controller.second->setDelegate(nullptr);
    }
  }

  void delegateEvent(sf::Event event)
  {
    // graceful Joystick connect/disconnect event handling
    if (event.type == sf::Event::JoystickConnected)
    {
      auto id = event.joystickConnect.joystickId;
      this->connect(getJoystickKey(id), new JoystickController(id));
      return;
    }
    else if (event.type == sf::Event::JoystickDisconnected)
    {
      auto id = event.joystickConnect.joystickId;

      if (this->map.count(getJoystickKey(id)))
      {
        this->map.erase(getJoystickKey(id));
      }

      return;
    }

    for (auto const &controller : map)
    {
      if (controller.second->pass(event))
        break;
    }
  }
};