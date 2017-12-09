//
// Created by fisk on 21/09/17.
//
#include <iostream>
#include "Renderer.h"
#include "scenes/SceneInterface.h"
#include <cmath>

void Renderer::main() {
  handleEvents();
  renderFrame();
}

void Renderer::onResize() {
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

void Renderer::handleGlobalEvents() {
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

void Renderer::handleEvents() {
  handleGlobalEvents();
  game->getScene()->handleEvents();
}

void Renderer::renderFrame() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  game->getScene()->render(this);
  window->display();
}

void Renderer::setGame(Asteroids *game) {
  this->game = game;
}

Renderer::Renderer(sf::RenderWindow *window) {
  if (!font->loadFromFile("Monospace.ttf")) {
    std::cout << "Runtime error: could not load Monospace.ttf font file";
    exit(1);
  }

  view.reset(sf::FloatRect(0, 0, 640, 480));
  this->window = window;

  onResize();
}
