#include <SFML/Graphics/RectangleShape.hpp>
#include "drawing.h"

// todo: change into composite sf::Drawable so shapes are not instantiated on the stack on every render call

namespace drawing {
void drawProgressBar(
    sf::RenderWindow *renderWindow,
    progress_bar_t options
) {
  auto bar = sf::RectangleShape();
  auto progress = sf::RectangleShape();

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
void centreText(sf::Text &text) {
    auto bounds = text.getLocalBounds();
    text.setOrigin(sf::Vector2f(int(bounds.left + bounds.width / 2), 0));
}
}