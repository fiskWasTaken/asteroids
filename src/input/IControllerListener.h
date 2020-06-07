#pragma once

#include "InputAction.h"
class IControllerListener {
 public:
  virtual void onAction(InputAction action, bool once) = 0;
};