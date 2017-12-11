#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "Asteroids.h"
#include "RendererInterface.h"

class Renderer : public RendererInterface {
 private:
  Asteroids *game;
  sf::RenderWindow *window;
  sf::View view;
  sf::Font *font = new sf::Font();
  int viewWidth = 640;
  int viewHeight = 480;

 public:
  explicit Renderer(sf::RenderWindow *window);

  void setGame(Asteroids *game);
  void renderFrame() override;
  void handleEvents() override;
  void handleGlobalEvents() override;
  void onResize() override;
  void main() override;

  inline sf::RenderWindow *getWindow() override {
    return window;
  }

  inline sf::Font *getFont() override {
    return font;
  }

  inline sf::View getView() override {
    return view;
  }
};