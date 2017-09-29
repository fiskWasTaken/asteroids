//
// Created by fisk on 21/09/17.
//
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Renderer.h"

void Renderer::render() {
  glEnable(GL_TEXTURE_2D);

  while (window->isOpen()) {
    renderFrame();

    struct timespec tim, tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 30000000;

    nanosleep(&tim, &tim2);
  }
}

void Renderer::renderFrame() {
  sf::Event event;

  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window->close();
      game->stop();
    } else if (event.type == sf::Event::Resized) {
      glViewport(0, 0, event.size.width, event.size.height);
    }
  }

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  auto world = game->getWorld();
  auto vec = sf::Vector2f((float) world->getWidth(), (float) world->getHeight());
  sf::RectangleShape shape(vec);
  shape.setFillColor(sf::Color::White);
  window->draw(shape);

  for (auto entity: world->getObjects()) {
    sf::RectangleShape shep(sf::Vector2f((float) entity->getWidth(), (float) entity->getHeight()));
    shep.setFillColor(sf::Color::Green);
    shep.setPosition(entity->getBoundingBox().first);
    window->draw(shep);
  }

  window->display();
}

Asteroids *Renderer::getGame() {
  return game;
}

void Renderer::setGame(Asteroids *game) {
  this->game = game;
}
