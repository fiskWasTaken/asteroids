#pragma once

#include <set>
#include <map>
#include "InputAction.h"
#include "IControllerListener.h"

class IController {
 protected:
  IControllerListener *delegate = nullptr;

 public:
  virtual void poll() = 0;

  void setDelegate(IControllerListener *listenerInterface) {
    delegate = listenerInterface;
  }

  IControllerListener *getDelegate() {
    return delegate;
  }

  void emit(InputAction action, bool once) {
    if (action != InputAction::NIL && delegate != nullptr)
      delegate->onAction(action, once);
  }

  virtual std::string getKeyString(InputAction action) = 0;

  virtual bool pass(sf::Event) = 0;
};