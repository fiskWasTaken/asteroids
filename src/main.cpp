#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "GameInterface.h"
#include "renderer/WindowRenderer.h"
#include "scenes/MainMenuScene.h"

void engine(Asteroids *game) {
  game->setScene(new MainMenuScene(game));
}

sf::ContextSettings getContextSettings() {
  sf::ContextSettings settings;
  settings.depthBits = 24;
  settings.stencilBits = 8;
  settings.antialiasingLevel = 0;
  settings.majorVersion = 2;
  settings.minorVersion = 1;
  return settings;
}

void renderer(Asteroids *game) {
  auto settings = getContextSettings();
  auto videoMode = sf::VideoMode(640, 480);
  auto window = new sf::RenderWindow(videoMode, "Asteroids", sf::Style::Default, settings);
  auto renderer = WindowRenderer(window, game);
  sf::Clock clock;

  glEnable(GL_TEXTURE_2D);
  while (window->isOpen()) {
    auto beforeRender = clock.getElapsedTime();
    renderer.main();
    game->main();
    auto afterCompute = clock.getElapsedTime();

    // Dynamic timestep
    struct timespec tim{}, tim2{};
    tim.tv_sec = 0;
    tim.tv_nsec = 30000000 - (afterCompute.asMicroseconds() * 1000 - beforeRender.asMicroseconds() * 1000);

    nanosleep(&tim, &tim2);
  }
}

int main() {
  auto game = new Asteroids();
  engine(game);
  renderer(game);
  return 0;
}