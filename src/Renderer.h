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
  sf::View view;
  sf::Font *font = new sf::Font();

 public:
  explicit Renderer(sf::RenderWindow *window);

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

  inline sf::View getView() {
    return view;
  }
};

#endif //ASTEROIDS_WINDOW_H
