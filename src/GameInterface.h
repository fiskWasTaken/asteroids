#pragma once

#include <scenes/SceneInterface.h>
#include "world/World.h"

class GameInterface {
 protected:
  SceneInterface *scene = nullptr;
  long tick = 0;

 public:
  void stop();

  // methods for game instance to implement
  virtual void main() = 0;

  void setScene(SceneInterface *scene);

  inline SceneInterface *getScene() {
    return scene;
  }
};