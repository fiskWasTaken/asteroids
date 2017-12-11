#pragma once

#include <iostream>
#include "renderer/RendererInterface.h"

class SceneInterface {
 public:
  virtual void render(RendererInterface *renderer) = 0;
  virtual void handleEvents() = 0;
  virtual void onVisible() = 0;
  virtual void main() {}

  virtual ~SceneInterface() = default;
};