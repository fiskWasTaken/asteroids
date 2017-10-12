//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_SCENES_ISCENE_H
#define ASTEROIDS_SCENES_ISCENE_H

#include "../Renderer.h"

class Renderer;

class SceneInterface {
 public:
  virtual void render(Renderer *renderer) = 0;
  virtual void handleEvents() = 0;
  virtual void onVisible() = 0;
  virtual void onDestroy() = 0;
};

#endif //ASTEROIDS_SCENES_ISCENE_H
