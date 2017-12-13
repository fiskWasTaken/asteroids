#include <utility/vector.h>
#include <SFML/Graphics/ConvexShape.hpp>
#include <utility/drawing.h>
#include "Asteroid.h"
#include "player/PlayerSession.h"

void Asteroid::onDestroyed() {
  if (size > 13) {
    auto ast1 = new Asteroid(world, size / 2);
    ast1->pos.x = pos.x - 6;
    ast1->pos.y = pos.y;
    ast1->vel = vector::rot(vel, vector::rot(vel) + 5);

    world->pushObject(ast1);

    auto ast2 = new Asteroid(world, size / 2);
    ast2->pos.x = pos.x + 6;
    ast2->pos.y = pos.y;
    ast2->vel = vector::rot(vel, vector::rot(vel) - 5);

    world->pushObject(ast2);
  }
}


bool Asteroid::isRecyclable() {
  return isDestroyed();
}

void Asteroid::update() {
  this->pos += vel;
  this->rot += rotSpeed;
}

void Asteroid::renderTo(sf::RenderWindow *renderWindow) {
  auto shape = sf::ConvexShape();
  auto size = points.size();

  shape.setPointCount(size);

  for (size_t i = 0; i < size; i++) {
    shape.setPoint(i, points[i]);
  }

  shape.setFillColor(sf::Color::Transparent);
  shape.setOutlineColor(outlineColor);
  shape.setOutlineThickness(1.0F);
  shape.setPosition(pos);
  shape.setOrigin(origin.x, origin.y);
  shape.setRotation(rot);

  renderWindow->draw(shape);

  if (health < getMaxHealth()) {
    drawing::drawHealthBar(
        renderWindow,
        getHealth(),
        getMaxHealth(),
        sf::Vector2f(pos.x, pos.y + 40),
        sf::Vector2f(origin.x, 20)
    );
  }
}

void Asteroid::onBulletHit(Bullet *bullet) {
  // take damage
  takeDamage(10);
  vel.x += bullet->vel.x / 30;
  vel.y += bullet->vel.y / 30;
  bullet->setLifetime(0);

  if (isDestroyed()) {
    auto session = bullet->getOwner();
    session->setScore(session->getScore() + getScoreValue());
  }
}

void Asteroid::onAsteroidHit(Asteroid *other) {
  // bounce
  auto diff = vel - other->vel;
  diff.x /= 1.1;
  diff.y /= 1.1;

  vel -= diff;
  other->vel += diff;

  auto rotDiff = rotSpeed - other->rotSpeed;
  rotDiff /= 10.0;

  rotSpeed -= rotDiff;
  other->rotSpeed += rotDiff;
}

void Asteroid::onShipHit(Ship *other) {
  if (!other->isOnInvincibilityCooldown()) {
    other->onDestroyed();
  }
}

void Asteroid::onCollision(AbstractWorldObject *other) {
  if (other->getClass() == WorldObjectClass::BULLET) {
    onBulletHit(dynamic_cast<Bullet *>(other));
  }

  if (other->getClass() == WorldObjectClass::ASTEROID) {
    onAsteroidHit(dynamic_cast<Asteroid *>(other));
  }

  if (other->getClass() == WorldObjectClass::SHIP) {
    onShipHit(dynamic_cast<Ship *>(other));
  }
}