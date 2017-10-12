//
// Created by fisk on 21/09/17.
//
#include <iostream>
#include "Renderer.h"
#include "scenes/SceneInterface.h"

void Renderer::run() {
  glEnable(GL_TEXTURE_2D);

  auto world = game->getWorld();

  window->setSize(sf::Vector2<unsigned int>(
      (unsigned int) world->getWidth(),
      (unsigned int) world->getHeight()
  ));

  while (window->isOpen()) {
    main();

    struct timespec tim, tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 30000000;

    nanosleep(&tim, &tim2);
  }
}

void Renderer::main() {
  handleEvents();
  renderFrame();
}

void Renderer::onResize() {
  auto videoMode = sf::VideoMode(game->getWorld()->getWidth(), game->getWorld()->getHeight());

  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 4;
  settings.majorVersion = 2;
  settings.minorVersion = 1;

  window->create(videoMode, "Asteroids", sf::Style::Default, settings);
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
