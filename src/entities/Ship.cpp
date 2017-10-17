//
// Created by fisk on 21/09/17.
//

#include <cmath>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include "Ship.h"
#include "Bullet.h"

void Ship::update() {
  if (isFiring) {
    if (fireCooldown != 0) {
      fireCooldown--;
    } else {
      auto thisRot = getRotationVector();
      auto velocity = thisRot * 5.0F;
      auto bullet = new Bullet(world);

      bullet->pos.x = pos.x + thisRot.x * 10;
      bullet->pos.y = pos.y + thisRot.y * 10;
      bullet->vel.x = velocity.x + vel.x;
      bullet->vel.y = velocity.y + vel.y;
      bullet->rot = rot;

      vel.x -= bullet->vel.x / 100;
      vel.y -= bullet->vel.y / 100;

      world->pushObject(bullet);
      fireCooldown = fireRate;
    }
  }

  isFiring = false;
  this->pos += vel;
}

void Ship::onDestroyed() {
  playerSession->setLives(playerSession->getLives() - 1);
  playerSession->getPlayer()->getController()->setDelegate(nullptr);
  isDestroyed = true;
  playerSession->spawnShip(world);
}

float Ship::getSpeed() {
  return sqrt(vel.x * vel.x + vel.y * vel.y);
}

void Ship::limitSpeed() {
  auto len = getSpeed();

  if (len > maxSpeed) {
    vel.x = vel.x / len * maxSpeed;
    vel.y = vel.y / len * maxSpeed;
  }
}

void Ship::onAction(InputAction action) {
  if (action == InputAction::ACCELERATE) {
    // get the vector for the ship's rotation
    auto rV = getRotationVector();

    // get the current speed
    auto speed = getSpeed();

    speed += 0.1;

    // the target vector, which is the rotation multiplied by the current speed
    auto target = rV * speed;

    auto diff = target - vel;

    // todo: the new velocity should be a step towards the target
    // instead of immediately snapping to the target
    vel.x += diff.x / 1;
    vel.y += diff.y / 1;
    limitSpeed();
  }

  if (action == InputAction::BRAKE) {
    // really we're just going in reverse
    vel.x /= 2;
    vel.y /= 2;
    limitSpeed();
  }

  if (action == InputAction::LEFT) {
    rot -= maxRotateSpeed;

    if (rot < -180) {
      rot += 360;
    }
  }

  if (action == InputAction::RIGHT) {
    rot += maxRotateSpeed;

    if (rot > 180) {
      rot -= 360;
    }
  }

  if (action == InputAction::FIRE) {
    isFiring = true;
  }
}

sf::Vector2f Ship::getRotationVector() {
  float r = 3.14159265F/180;
  return {cos(rot*r), sin(rot*r)};
}

bool Ship::isRecyclable() {
  return isDestroyed;
}

sf::Drawable *Ship::getDrawable() {
  auto shep = new sf::ConvexShape();

  shep->setPointCount(3);

  shep->setPoint(0, sf::Vector2f(20, 10));
  shep->setPoint(1, sf::Vector2f(0, 0));
  shep->setPoint(2, sf::Vector2f(0, 20));

  shep->setFillColor(sf::Color::Transparent);
  shep->setOutlineColor(sf::Color::Green);
  shep->setOutlineThickness(1.0F);
  shep->setPosition(pos);
  shep->setOrigin(10, 10);
  shep->setRotation(rot);
  return shep;
}
