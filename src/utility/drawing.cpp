#include <SFML/Graphics/RectangleShape.hpp>
#include "drawing.h"

namespace drawing {
void drawHealthBar(
    sf::RenderWindow *renderWindow,
    int health,
    int maxHealth,
    sf::Vector2f pos,
    sf::Vector2f origin
) {
  // health bar
  int height = 3;
  auto healthBar = sf::RectangleShape();
  auto remainingHealth = sf::RectangleShape();

  remainingHealth.setPosition(pos);
  remainingHealth.setOrigin(origin);
  remainingHealth.setSize(sf::Vector2f(health, height));
  remainingHealth.setOutlineColor(sf::Color::Transparent);
  remainingHealth.setFillColor(sf::Color::Red);

  healthBar.setPosition(pos);
  healthBar.setOrigin(origin);
  healthBar.setSize(sf::Vector2f(maxHealth, height));
  healthBar.setOutlineThickness(1.0f);
  healthBar.setFillColor(sf::Color::Transparent);
  healthBar.setOutlineColor(sf::Color(127, 127, 127));

  renderWindow->draw(healthBar);
  renderWindow->draw(remainingHealth);
}
}