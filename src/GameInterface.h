#pragma once

#include <scenes/SceneInterface.h>
#include "world/World.h"

class GameInterface {
 protected:
  SceneInterface *scene = nullptr;
  long tick = 0;

 public:
  void stop();
  virtual void main() = 0;
  void setScene(SceneInterface *scene);
  SceneInterface *getScene() { return scene; }
};