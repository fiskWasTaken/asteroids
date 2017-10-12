//
// Created by fisk on 21/09/17.
//

#include <cmath>
#include "Ship.h"
#include "Bullet.h"

void Ship::update(World *world) {
  if (isFiring) {
    auto velocity = getRotationVector() * 5.0F;
    auto bullet = new Bullet();

    bullet->pos.x = pos.x;
    bullet->pos.y = pos.y;
    bullet->vel.x = velocity.x;
    bullet->vel.y = velocity.y;
    bullet->rot = rot;

    world->pushObject(bullet);
  }

  isFiring = false;
  this->pos += vel;
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

    // todo: the new velocity should be a step towards the target
    // instead of immediately snapping to the target
    vel.x = target.x;
    vel.y = target.y;
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
  return false;
}