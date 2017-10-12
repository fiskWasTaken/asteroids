#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "Game.h"
#include "Renderer.h"
#include "entities/Asteroid.h"
#include "entities/Ship.h"
#include "input/Controller.h"
#include "input/KeyboardController.h"
#include "scenes/GameScene.h"
#include "scenes/MainMenuScene.h"

void engine(Asteroids *game) {
  game->setScene(new MainMenuScene(game));
//  game->run();
}

void renderer(Asteroids *game) {
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 4;
  settings.majorVersion = 2;
  settings.minorVersion = 1;

  auto videoMode = sf::VideoMode(1, 1);

  auto window = new sf::RenderWindow(videoMode, "Asteroids", sf::Style::Default, settings);
  auto renderer = new Renderer(window);
  renderer->setGame(game);
//  renderer->run();

  renderer->onResize();

  glEnable(GL_TEXTURE_2D);

  while (window->isOpen()) {
    renderer->main();
    game->main();

    struct timespec tim, tim2;
    tim.tv_sec = 0;
    tim.tv_nsec = 30000000;

    nanosleep(&tim, &tim2);
  }
}

int main() {
  auto game = new Asteroids();
  engine(game);

//  std::thread eng(engine, game);

  /*
   * The window runs on the main thread. This is due to a limitation
   * in macOS where windows cannot be created in worker threads.
   */
  renderer(game);
//  eng.join();
  return 0;
}