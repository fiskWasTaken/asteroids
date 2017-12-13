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

  inline void setDelegate(ControllerListenerInterface *listenerInterface) {
    delegate = listenerInterface;
  }

  inline ControllerListenerInterface *getDelegate() {
    return delegate;
  }

  void emit(InputAction action) {
    if (action != InputAction::NIL && delegate != nullptr)
      delegate->onAction(action);
  }

  virtual std::string getKeyString(InputAction action) = 0;
};