#pragma once

#include <set>
#include <map>
#include "InputAction.h"
#include "ControllerListenerInterface.h"

class ControllerInterface {
 protected:
  ControllerListenerInterface *delegate = nullptr;

 public:
  virtual void poll() = 0;

  void setDelegate(ControllerListenerInterface *listenerInterface) {
    delegate = listenerInterface;
  }

  ControllerListenerInterface *getDelegate() {
    return delegate;
  }

  void emit(InputAction action, bool once) {
    if (action != InputAction::NIL && delegate != nullptr)
      delegate->onAction(action, once);
  }

  virtual std::string getKeyString(InputAction action) = 0;

  virtual bool pass(sf::Event) = 0;
};