//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_RENDERER_H
#define ASTEROIDS_RENDERER_H

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "Asteroids.h"

class Renderer {
 private:
  Asteroids *game;
  sf::RenderWindow *window;
  sf::Font *font = new sf::Font();

 public:
  Renderer(sf::RenderWindow *window) {
    this->window = window;

    if (!font->loadFromFile("Monospace.ttf")) {
      std::cout << "Runtime error: could not load Monospace.ttf font file";
      exit(1);
    }
  }

  void run();
  void setGame(Asteroids *game);
  void renderFrame();
  void handleEvents();
  void handleGlobalEvents();
  void onResize();
  void main();

  inline sf::RenderWindow *getWindow() {
    return window;
  }

  inline Asteroids *getGame() {
    return game;
  }

  inline sf::Font *getFont() {
    return font;
  }
};

#endif //ASTEROIDS_WINDOW_H
