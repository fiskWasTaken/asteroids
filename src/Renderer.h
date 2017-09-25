//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_RENDERER_H
#define ASTEROIDS_RENDERER_H

#include "Asteroids.h"
class Renderer {
 private:
  Asteroids *game;
  sf::RenderWindow *window;

 public:
  Renderer(sf::RenderWindow *window) {
    this->window = window;
  }

  void render();
  Asteroids *getGame();
  void setGame(Asteroids *game);
  void renderFrame();
};

#endif //ASTEROIDS_WINDOW_H
