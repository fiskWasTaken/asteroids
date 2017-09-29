#include <thread>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Renderer.h"
#include "entities/Asteroid.h"

void engine(Asteroids *game) {
  auto player = new Player("Player 1");
  auto session = new PlayerSession(player);

  auto ast = new Asteroid();
  ast->pos.x = 5;
  ast->pos.y = 5;
  ast->vel.x = 2;
  ast->vel.y = 1;
  ast->setHeight(32);
  ast->setWidth(32);

  game->getWorld()->pushObject(ast);
  game->getSessions()->push_back(session);
  game->run();
}

void renderer(Asteroids *game) {
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 4;
  settings.majorVersion = 2;
  settings.minorVersion = 1;

  auto window = new sf::RenderWindow(sf::VideoMode(800, 600), "Asteroids", sf::Style::Default, settings);
  auto renderer = new Renderer(window);
  renderer->setGame(game);
  renderer->render();
}

int main() {
  auto game = new Asteroids();

  std::thread eng(engine, game);

  renderer(game);
  eng.join();
  return 0;
}