//
// Created by Fisk on 09/10/2017.
//

#ifndef ASTEROIDS_CONTROLLERLISTENERINTERFACE_H
#define ASTEROIDS_CONTROLLERLISTENERINTERFACE_H

#include "InputAction.h"
class ControllerListenerInterface {
 public:
  virtual void onAction(InputAction action) = 0;
};

#endif //ASTEROIDS_CONTROLLERLISTENERINTERFACE_H
