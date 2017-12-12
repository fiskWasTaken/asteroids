#include <iostream>
#include "WindowRenderer.h"
#include <cmath>

void WindowRenderer::main() {
  handleEvents();
  renderFrame();
}

void WindowRenderer::onResize() {
  auto windowSize = window->getSize();
  float desiredRatio = float(viewWidth) / viewHeight;
  float aspectRatio = float(windowSize.x) / windowSize.y;

  float ySize = 1 / (desiredRatio / aspectRatio);
  float yMargin = (1 - ySize) / 2;

  float xSize = 1;
  float xMargin = (1 - xSize) / 2;

  view.setViewport(sf::FloatRect(xMargin, yMargin, xSize, ySize));
  window->setView(view);
}

void WindowRenderer::handleGlobalEvents() {
  sf::Event event{};

  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window->close();
      game->stop();
    } else if (event.type == sf::Event::Resized) {
      onResize();
    }
  }
}

void WindowRenderer::handleEvents() {
  handleGlobalEvents();
  game->getScene()->handleEvents();
}

void WindowRenderer::renderFrame() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  game->getScene()->render(this);
  window->display();
}

WindowRenderer::WindowRenderer(sf::RenderWindow *window, Asteroids *game) {
  if (!font.loadFromFile("Monospace.ttf")) {
    std::cout << "Runtime error: could not load Monospace.ttf font file";
    exit(1);
  }

  view.reset(sf::FloatRect(0, 0, 640, 480));
  this->window = window;
  this->game = game;

  onResize();
}
