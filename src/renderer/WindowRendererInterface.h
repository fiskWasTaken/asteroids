#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class WindowRendererInterface {
 public:
  virtual void renderFrame() = 0;
  virtual void handleEvents() = 0;
  virtual void handleGlobalEvents() = 0;
  virtual void onResize() = 0;
  virtual void main() = 0;

  virtual sf::RenderWindow *getWindow() = 0;
  virtual sf::Font getFont() = 0;
  virtual sf::View getView() = 0;
};