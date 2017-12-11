//
// Created by fisk on 21/09/17.
//

#include <cmath>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <scenes/GameScene.h>
#include "Bullet.h"
#include "../utility/vector.h"

void Ship::update() {
  if (fireCooldown != 0) {
    fireCooldown--;
  } else if (isFiring) {
    auto thisRot = vector::fromAngle(rot);
    auto velocity = thisRot * 5.0F;
    auto bullet = new Bullet(world);

    bullet->pos.x = pos.x + thisRot.x * 10;
    bullet->pos.y = pos.y + thisRot.y * 10;
    bullet->vel = velocity + vel;
    bullet->rot = rot;

    vel.x -= bullet->vel.x / 100;
    vel.y -= bullet->vel.y / 100;

    world->pushObject(bullet);
    fireCooldown = fireRate;
  }

  this->isFiring = false;

  vel = *vector::limit(&vel, maxSpeed);
  this->pos += vel;
}

void Ship::onDestroyed() {
  auto scene = dynamic_cast<GameScene *>(world->getGame()->getScene());
  isDestroyed = true;
  scene->onShipDestroyed(playerSession);
}

void Ship::onAction(InputAction action) {
  if (action == InputAction::ACCELERATE) {
    // get the vector for the ship's rotation
    auto rV = vector::fromAngle(rot);

    // get the current speed
    auto speed = vector::len(&vel);

    speed += 0.1;

    // the target vector, which is the rotation multiplied by the current speed
    auto target = rV * speed;

    auto diff = target - vel;

    // todo: the new velocity should be a step towards the target
    // instead of immediately snapping to the target
    vel.x += diff.x;
    vel.y += diff.y;
  }

  if (action == InputAction::BRAKE) {
    // really we're just going in reverse
    vel.x /= 2;
    vel.y /= 2;
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

  if (action == InputAction::PANIC) {
    onDestroyed();
  }

  if (action == InputAction::PAUSE) {
    auto scene = dynamic_cast<GameScene *>(world->getGame()->getScene());
    scene->pause(this->playerSession);
  }
}

bool Ship::isRecyclable() {
  return isDestroyed;
}

void Ship::renderTo(sf::RenderWindow *renderWindow) {
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
