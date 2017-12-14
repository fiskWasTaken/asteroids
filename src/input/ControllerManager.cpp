#include <SFML/Window/Event.hpp>
#include "ControllerManager.h"
#include "JoystickController.h"

std::string getJoystickKey(int id) {
  return "j" + std::to_string(id);
}

void ControllerManager::delegateEvent(sf::Event event) {
  // graceful Joystick connect/disconnect event handling
  if (event.type == sf::Event::JoystickConnected) {
    auto id = event.joystickConnect.joystickId;
    this->registerController(getJoystickKey(id), new JoystickController(id));
    return;
  } else if (event.type == sf::Event::JoystickDisconnected) {
    auto id = event.joystickConnect.joystickId;

    if (this->map.count(getJoystickKey(id))) {
      this->map.erase(getJoystickKey(id));
    }

    return;
  }

  for (auto const &controller : map) {
    if (controller.second->pass(event))
      break;
  }
}
