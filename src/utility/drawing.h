#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

struct progress_bar_t
{
  int progress = 0;
  int maxProgress = 0;
  int height = 3;
  int gutter = 0;
  sf::Vector2f pos;
  sf::Vector2f origin;
  sf::Color fillColor;
  sf::Color outlineColor = sf::Color(127, 127, 127);
};

namespace drawing
{

  inline void drawProgressBar(
      sf::RenderWindow *renderWindow,
      progress_bar_t options)
  {
    sf::RectangleShape bar;
    sf::RectangleShape progress;

    progress.setPosition(options.pos);
    progress.setOrigin(options.origin);
    progress.setSize(sf::Vector2f(options.progress, options.height));
    progress.setOutlineColor(sf::Color::Transparent);
    progress.setFillColor(options.fillColor);

    bar.setPosition(options.pos - sf::Vector2f(options.gutter, options.gutter));
    bar.setOrigin(options.origin);
    bar.setSize(sf::Vector2f(options.maxProgress + (options.gutter * 2), options.height + (options.gutter * 2)));
    bar.setOutlineThickness(1.0f);
    bar.setFillColor(sf::Color::Transparent);
    bar.setOutlineColor(options.outlineColor);

    renderWindow->draw(bar);
    renderWindow->draw(progress);
  }

  inline void centreText(sf::Text &text)
  {
    auto bounds = text.getLocalBounds();
    text.setOrigin(sf::Vector2f(int(bounds.left + bounds.width / 2), 0));
  }
} // namespace drawing