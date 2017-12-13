#pragma once

#include "KeyboardController.h"
#include "JoystickController.h"

namespace presets {
ControllerInterface *getDefaultK0Controller();
ControllerInterface *getDefaultK1Controller();
ControllerInterface *getDefaultJoystickController(unsigned int index);
};


