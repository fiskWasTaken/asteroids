//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include "World.h"

class SceneInterface;

class Game {
 protected:
  SceneInterface *scene;
  long tick;
  bool running = false;

 public:
  void run();
  void stop();

  // methods for game instance to implement
  virtual void main() = 0;

  void setScene(SceneInterface *scene);

  inline SceneInterface *getScene() {
    return scene;
  }
};

#endif //ASTEROIDS_GAME_H
