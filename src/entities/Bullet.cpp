#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Bullet.h"

void Bullet::setLifetime(int lifetime) {
  this->lifetime = lifetime;
}

void Bullet::renderTo(sf::RenderWindow *renderWindow) {
  auto shape = sf::CircleShape(1, 3);
  shape.setFillColor(sf::Color::Transparent);
  shape.setOutlineColor(sf::Color::Green);
  shape.setOutlineThickness(1.0F);
  shape.setPosition(pos);
  shape.setOrigin(origin.x, origin.y);
  shape.setRotation(rot + 90);

  renderWindow->draw(shape);
}