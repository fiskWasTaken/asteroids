
#include "Bullet.h"

void Bullet::setLifetime(int lifetime) {
  this->lifetime = lifetime;
}

void Bullet::renderTo(sf::RenderWindow *renderWindow) {
  shape.setPosition(pos);
  shape.setRotation(rot);

  renderWindow->draw(shape);
}