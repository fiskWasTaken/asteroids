#include "GameInterface.h"

void GameInterface::stop() {
}

void GameInterface::setScene(SceneInterface *scene) {
  if (this->scene != nullptr) {
    delete (this->scene);
  }

  this->scene = scene;
  scene->onVisible();
}
