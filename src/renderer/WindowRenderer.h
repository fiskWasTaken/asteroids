#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "Asteroids.h"
#include "WindowRendererInterface.h"

class WindowRenderer : public WindowRendererInterface {
 private:
  Asteroids *game;
  sf::RenderWindow *window;
  sf::View view;
  sf::Font font;
  int viewWidth = 640;
  int viewHeight = 480;

 public:
  WindowRenderer(sf::RenderWindow *window, Asteroids *game);

  void renderFrame() override;
  void handleEvents() override;
  void onResize() override;
  void main() override;

  sf::RenderWindow *getWindow() override {
    return window;
  }

  sf::Font getFont() override {
    return font;
  }

  sf::View getView() override {
    return view;
  }
};