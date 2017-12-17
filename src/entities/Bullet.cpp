
#include <utility/vector.h>
#include "Bullet.h"
#include "../player/PlayerSession.h"

void Bullet::setLifetime(int lifetime) {
  this->lifetime = lifetime;
}

void Bullet::renderTo(sf::RenderWindow *renderWindow) {
  shape.setPosition(pos);
  shape.setRotation(rot);

  renderWindow->draw(shape);

  particleSystem.fuel(1);
  particleSystem.setGravity(-vel.x, -vel.y);
  particleSystem.remove();
  particleSystem.update();
  particleSystem.render();

  auto offset = vector::fromAngle(rot) * -origin.x;

  auto sprite = particleSystem.getSprite();
  sprite.setPosition(pos.x + offset.x - 64, pos.y + offset.y - 64);
  renderWindow->draw(sprite);
}

Bullet::Bullet(WorldInterface *world, PlayerSession *owner) : AbstractWorldObject(world), particleSystem(128, 128) {
  points = shape::generateShape(3, 1);
  origin = sf::Vector2f(1, 1);
  this->owner = owner;

  // create an empty shape
  auto size = points.size();

  shape.setPointCount(size);

  for (size_t i = 0; i < size; i++) {
    shape.setPoint(i, points[i]);
  }

  shape.setFillColor(sf::Color::Transparent);
  shape.setOutlineColor(outlineColor);
  shape.setOutlineThickness(1.0F);
  shape.setOrigin(origin.x, origin.y);

  particleSystem.setColor(owner->getPlayer()->getColor());
  particleSystem.setDissolve(true);
  particleSystem.setDissolutionRate(40);
  particleSystem.setShape(Shape::CIRCLE);
}
