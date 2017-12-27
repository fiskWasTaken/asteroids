#include <SFML/Graphics/RectangleShape.hpp>
#include "drawing.h"

// todo: change into composite sf::Drawable so shapes are not instantiated on the stack on every render call

namespace drawing {
void drawProgressBar(
    sf::RenderWindow *renderWindow,
    progress_bar_t options
) {
  // health bar
  auto healthBar = sf::RectangleShape();
  auto remainingHealth = sf::RectangleShape();

  remainingHealth.setPosition(options.pos);
  remainingHealth.setOrigin(options.origin);
  remainingHealth.setSize(sf::Vector2f(options.progress, options.height));
  remainingHealth.setOutlineColor(sf::Color::Transparent);
  remainingHealth.setFillColor(options.fillColor);

  healthBar.setPosition(options.pos);
  healthBar.setOrigin(options.origin);
  healthBar.setSize(sf::Vector2f(options.maxProgress, options.height));
  healthBar.setOutlineThickness(1.0f);
  healthBar.setFillColor(sf::Color::Transparent);
  healthBar.setOutlineColor(options.outlineColor);

  renderWindow->draw(healthBar);
  renderWindow->draw(remainingHealth);
}
}