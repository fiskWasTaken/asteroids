#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include "Bullet.h"

void Bullet::setLifetime(int lifetime) {
  this->lifetime = lifetime;
}

void Bullet::renderTo(sf::RenderWindow *renderWindow) {
  // create an empty shape
  auto shape = sf::ConvexShape();

  shape.setPointCount(points.size());

  for (size_t i = 0; i < points.size(); i++) {
    shape.setPoint(i, points[i]);
  }

  shape.setFillColor(sf::Color::Transparent);
  shape.setOutlineColor(sf::Color(173, 173, 173));
  shape.setOutlineThickness(1.0F);
  shape.setPosition(pos);
  shape.setOrigin(origin.x, origin.y);
  shape.setRotation(rot);

  renderWindow->draw(shape);
}