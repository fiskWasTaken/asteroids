//
// Created by fisk on 21/09/17.
//
#include <iostream>
#include "Renderer.h"
#include "scenes/SceneInterface.h"

void Renderer::main() {
  handleEvents();
  renderFrame();
}

void Renderer::onResize() {

}

void Renderer::handleGlobalEvents() {
  sf::Event event{};

  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {

      window->close();
      game->stop();
    } else if (event.type == sf::Event::Resized) {
//      onResize();
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

  this->window = window;
  view.reset(sf::FloatRect(0, 0, 640, 480));
  view.setViewport(sf::FloatRect(0, 0, 1, 1));
  window->setView(view);
}
