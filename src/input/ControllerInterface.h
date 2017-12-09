//
// Created by fisk on 22/09/17.
//

#ifndef ASTEROIDS_CONTROLLER_H
#define ASTEROIDS_CONTROLLER_H

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
    if (delegate != nullptr)
      delegate->onAction(action);
  }
};

#endif //ASTEROIDS_CONTROLLER_H
