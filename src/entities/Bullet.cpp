//
// Created by fisk on 24/09/17.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Bullet.h"

sf::Drawable *Bullet::getDrawable() {
  auto shep = new sf::CircleShape(1, 3);
  shep->setFillColor(sf::Color::Transparent);
  shep->setOutlineColor(sf::Color::Green);
  shep->setOutlineThickness(1.0F);
  shep->setPosition(pos);
  shep->setOrigin(0, 0);
  shep->setRotation(rot + 90);
  return shep;
}
