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
  if (other->getClass() == WorldObjectClass::BULLET) {
    // take damage
    health -= 10;
  }

  if (other->getClass() == WorldObjectClass::ASTEROID) {
    // bounce
    vel = -vel;
    other->vel = -other->vel;
  }

  if (other->getClass() == WorldObjectClass::SHIP) {
    // kill ship
    ((Ship *) other)->onDestroyed();
  }
}

bool Asteroid::isRecyclable() {
  return health <= 0;
}

sf::Drawable *Asteroid::getDrawable() {
  // create an empty shape
  auto shep = new sf::ConvexShape();

  shep->setPointCount(points.size());

  for (int i = 0; i < points.size(); i++) {
    shep->setPoint(i, points[i]);
  }

  shep->setFillColor(sf::Color::Transparent);
  shep->setOutlineColor(sf::Color::Green);
  shep->setOutlineThickness(1.0F);
  shep->setPosition(pos);
  shep->setOrigin(25, 25);
  shep->setRotation(rot);
  return shep;
}

void Asteroid::onDestroyed() {

}
