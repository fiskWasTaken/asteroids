//
// Created by fisk on 21/09/17.
//

#include "GameInterface.h"

void GameInterface::stop() {
  running = false;
}

void GameInterface::setScene(SceneInterface *scene) {
  if (this->scene != nullptr)
    this->scene->onDestroy();

  this->scene = scene;
  scene->onVisible();
}
