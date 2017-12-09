//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include <scenes/SceneInterface.h>
#include "world/World.h"

class GameInterface {
 protected:
  SceneInterface *scene;
  long tick;
  bool running = false;

 public:
  void stop();

  // methods for game instance to implement
  virtual void main() = 0;

  void setScene(SceneInterface *scene);

  inline SceneInterface *getScene() {
    return scene;
  }
};

#endif //ASTEROIDS_GAME_H
