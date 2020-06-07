#pragma once

#include <iostream>
#include "renderer/IWindowRenderer.h"

class IScene
{
public:
  virtual void render(IWindowRenderer *renderer) = 0;
  virtual void onVisible() = 0;
  virtual void main() {}

  virtual ~IScene() = default;
};