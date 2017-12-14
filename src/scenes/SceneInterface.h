#pragma once

#include <iostream>
#include "renderer/WindowRendererInterface.h"

class SceneInterface {
 public:
  virtual void render(WindowRendererInterface *renderer) = 0;
  virtual void onVisible() = 0;
  virtual void main() {}

  virtual ~SceneInterface() = default;
};