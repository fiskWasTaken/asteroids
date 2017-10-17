//
// Created by fisk on 21/09/17.
//

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include "Asteroid.h"
#include "Ship.h"

void Asteroid::update() {
  this->pos += vel;
  this->rot += 0.1F;
}

void Asteroid::onCollision(AbstractWorldObject *other) {
  if (other->OBJECT_CLASS == WorldObjectClass::BULLET) {
    // take damage
    health -= 10;
  }

  if (other->OBJECT_CLASS == WorldObjectClass::ASTEROID) {
    // bounce
    vel = -vel;
    other->vel = -other->vel;
  }

  if (other->OBJECT_CLASS == WorldObjectClass::SHIP) {
    // kill ship
    ((Ship*) other)->onDestroyed();
  }
}
bool Asteroid::isRecyclable() {
  return health <= 0;
}

sf::Drawable *Asteroid::getDrawable() {
  // create an empty shape
  auto shep = new sf::ConvexShape();

  shep->setPointCount(5);

  shep->setPoint(0, sf::Vector2f(0, 0));
  shep->setPoint(1, sf::Vector2f(50, 10));
  shep->setPoint(2, sf::Vector2f(50, 45));
  shep->setPoint(3, sf::Vector2f(30, 50));
  shep->setPoint(4, sf::Vector2f(0, 50));

  shep->setFillColor(sf::Color::Transparent);
  shep->setOutlineColor(sf::Color::Green);
  shep->setOutlineThickness(1.0F);
  shep->setPosition(pos);
  shep->setOrigin(getWidth() / 2, getHeight() / 2);
  shep->setRotation(rot);
  return shep;
}

void Asteroid::onDestroyed() {

}
