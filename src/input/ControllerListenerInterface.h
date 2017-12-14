#pragma once

#include "InputAction.h"
class ControllerListenerInterface {
 public:
  virtual void onAction(InputAction action, bool once) = 0;
};