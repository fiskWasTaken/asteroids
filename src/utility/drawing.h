#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

struct progress_bar_t {
  int progress = 0;
  int maxProgress = 0;
  int height = 3;
  int gutter = 0;
  sf::Vector2f pos;
  sf::Vector2f origin;
  sf::Color fillColor;
  sf::Color outlineColor = sf::Color(127, 127, 127);
};

namespace drawing {
void drawProgressBar(
    sf::RenderWindow *renderWindow,
    progress_bar_t options
);
}