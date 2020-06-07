#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include "IGame.h"
#include "IWindowRenderer.h"

class WindowRenderer : public IWindowRenderer
{
protected:
  IGame *game;
  sf::RenderWindow *window;
  sf::View view;
  sf::Font font;
  int viewWidth = 640;
  int viewHeight = 480;

public:
  WindowRenderer(sf::RenderWindow *window, IGame *game)
  {
    if (!font.loadFromFile("Monospace.ttf"))
    {
      std::cout << "Runtime error: could not load Monospace.ttf font file";
      exit(1);
    }

    view.reset(sf::FloatRect(0, 0, 640, 480));
    this->window = window;
    this->game = game;

    onResize();
  }

  void renderFrame()
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    game->getScene()->render(this);
    window->display();
  }

  void handleEvents()
  {
    sf::Event event{};

    while (window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window->close();
        game->stop();
      }
      else if (event.type == sf::Event::Resized)
      {
        onResize();
      }
      else
      {
        // Other events are sent to the controller manager for delegation
        game->getControllers().delegateEvent(event);
      }
    }

    for (auto controller : game->getControllers().getControllers())
    {
      controller.second->poll();
    }
  }

  void onResize()
  {
    auto windowSize = window->getSize();

    // retain the aspect ratio of the game when resized
    // todo: can we deduplicate this?

    if (windowSize.y > windowSize.x)
    {
      float desiredRatio = float(viewWidth) / viewHeight;
      float aspectRatio = float(windowSize.x) / windowSize.y;
      float ySize = 1 / (desiredRatio / aspectRatio);
      float yMargin = (1 - ySize) / 2;

      view.setViewport(sf::FloatRect(0, yMargin, 1, ySize));
    }
    else
    {
      float desiredRatio = float(viewHeight) / viewWidth;
      float aspectRatio = float(windowSize.y) / windowSize.x;
      float xSize = 1 / (desiredRatio / aspectRatio);
      float xMargin = (1 - xSize) / 2;

      view.setViewport(sf::FloatRect(xMargin, 0, xSize, 1));
    }

    window->setView(view);
  }

  void main()
  {
    handleEvents();
    renderFrame();
  }

  sf::RenderWindow *getWindow() { return window; }
  sf::Font getFont() { return font; }
  sf::View getView() { return view; }
};