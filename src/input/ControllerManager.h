#pragma once

#include "ControllerInterface.h"
class ControllerManager {
 private:
  std::map<std::string, ControllerInterface*> map;

 public:
  /**
   * Register a controller
   * @param id The unique key for this controller
   * @param controller The controller
   */
  inline void registerController(const std::string &id, ControllerInterface *controller) {
    map[id] = controller;
  }

  /**
   * @param id
   * @return The controller identified by this key, or the best available if not found
   */
  inline ControllerInterface* getController(std::string id) {
    if (map[id] == nullptr) {
      return getFirstAvailable();
    }

    return map[id];
  }

  inline std::map<std::string, ControllerInterface*> getControllers() {
    return map;
  };

  /**
   * @return The first available controller.
   */
  inline ControllerInterface* getFirstAvailable() {
    for (auto const& controller : map) {
      if (controller.second->getDelegate() == nullptr) {
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
  inline ControllerInterface* getFirst() {
    return map.begin()->second;
  }
};
