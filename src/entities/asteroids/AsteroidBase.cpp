//
// Created by fisk on 11/12/17.
//

#include <SFML/Graphics/ConvexShape.hpp>
#include <entities/Bullet.h>
#include <entities/Ship.h>
#include "AsteroidBase.h"

bool AsteroidBase::isRecyclable() {
  return health <= 0;
}

void AsteroidBase::update() {
  this->pos += vel;
  this->rot += 0.1F;
}

void AsteroidBase::renderTo(sf::RenderWindow *renderWindow) {
  // create an empty shape
  auto shape = sf::ConvexShape();

  shape.setPointCount(points.size());

  for (int i = 0; i < points.size(); i++) {
    shape.setPoint(i, points[i]);
  }

  shape.setFillColor(sf::Color::Transparent);
  shape.setOutlineColor(sf::Color::Green);
  shape.setOutlineThickness(1.0F);
  shape.setPosition(pos);
  shape.setOrigin(origin.x, origin.y);
  shape.setRotation(rot);

  renderWindow->draw(shape);
}

void AsteroidBase::onCollision(AbstractWorldObject *other) {
  if (other->getClass() == WorldObjectClass::BULLET) {
    // take damage
    takeDamage(10);
    vel.x += other->vel.x / 30;
    vel.y += other->vel.y / 30;
    ((Bullet *) other)->setLifetime(0);
  }

  if (other->getClass() == WorldObjectClass::ASTEROID) {
    // bounce
    vel = -vel;
  }

  if (other->getClass() == WorldObjectClass::SHIP) {
    // kill ship
    ((Ship *) other)->onDestroyed();
  }
}