#pragma once

#include "renderer/RendererInterface.h"

class SceneInterface {
 public:
  virtual void render(RendererInterface *renderer) = 0;
  virtual void handleEvents() = 0;
  virtual void onVisible() = 0;
  virtual void onDestroy() = 0;
  virtual void main() {}
};