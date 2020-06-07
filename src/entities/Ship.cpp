#include <cmath>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include "../utility/vector.h"
#include "TemporaryParticle.h"

#include <scenes/GameScene.h>

void Ship::fireBullet() {
  auto thisRot = vector::fromAngleDeg(rot);
  auto velocity = thisRot * 5.0F;
  auto bullet = new Bullet(world, this->playerSession);

  bullet->pos.x = pos.x + thisRot.x * 10;
  bullet->pos.y = pos.y + thisRot.y * 10;
  bullet->vel = velocity + vel;
  bullet->rot = rot;

  vel.x -= bullet->vel.x / 100;
  vel.y -= bullet->vel.y / 100;

  world->push(bullet);
}

void Ship::fireAltWeapon() {
  for (int i = 0; i < 10; i++) {
    auto thisRot = vector::fromAngleDeg(rot + i * 2 - 10);
    auto velocity = thisRot * 5.0F;
    auto bullet = new Bullet(world, this->playerSession);
    bullet->pos.x = pos.x + thisRot.x * 10;
    bullet->pos.y = pos.y + thisRot.y * 10;
    bullet->vel = velocity + vel;
    bullet->rot = rot;
    world->push(bullet);
  }
}

void Ship::update() {
  if (fireCooldown != 0) {
    fireCooldown--;
  } else if (isFiring) {
    fireBullet();
    fireCooldown = FIRE_RATE;
  }

  isFiring = false;

  if (altFireCooldown != 0) {
    altFireCooldown--;
  } else if (isFiringAltWeapon) {
    fireAltWeapon();
    altFireCooldown = ALT_FIRE_RATE;
  }

  isFiringAltWeapon = false;

  vel += acc;
  acc = {0, 0};
  vel = vector::limit(vel, MAX_SPEED);
  this->pos += vel;

  vel *= 0.95F;

  if (isOnInvincibilityCooldown()) {
    invincibilityTimer--;
  }
}

void Ship::onDestroyed() {
  auto scene = dynamic_cast<GameScene *>(world->getGame()->getScene());
  isDestroyed = true;
  scene->onShipDestroyed(playerSession);

  auto explosion = new ParticleSystem(128, 128);
  explosion->setColor(color);
  explosion->setParticleSpeed(40);
  explosion->fuel(50);
  explosion->setDissolve(true);
  explosion->setDissolutionRate(10);
  explosion->setShape(Shape::CIRCLE);
  auto emitter = new TemporaryParticle(world, explosion);
  emitter->pos.x = pos.x;
  emitter->pos.y = pos.y;
  world->push(emitter);
}

void Ship::onAction(InputAction action, bool once) {
  // todo: switch

  if (action == InputAction::ACCELERATE) {
    // get the current speed
    auto target = vector::fromAngleDeg(rot) * MAX_SPEED;
    auto diff = target - acc;

    diff *= 0.10F;

    acc.x = diff.x;
    acc.y = diff.y;

//    printf("pos: %.2f, %.2f vel: %.2f, %.2f acc: %.2f, %.2f\n", pos.x, pos.y, vel.x, vel.y, acc.x, acc.y);
    isThrusting = true;
  }

  if (action == InputAction::BRAKE) {
    // really we're just going in reverse
    auto target = vector::fromAngleDeg(rot) * MAX_SPEED;
    auto diff = target - acc;

    diff *= 0.10F;

    acc.x = -diff.x;
    acc.y = -diff.y;
  }

  if (action == InputAction::LEFT) {
    rot -= MAX_ROTATE_SPEED;

    if (rot < -180) {
      rot += 360;
    }
  }

  if (action == InputAction::RIGHT) {
    rot += MAX_ROTATE_SPEED;

    if (rot > 180) {
      rot -= 360;
    }
  }

  if (action == InputAction::FIRE) {
    isFiring = true;
  }

  if (action == InputAction::ALTFIRE) {
    isFiringAltWeapon = true;
  }

  if (action == InputAction::PANIC && once) {
    onDestroyed();
  }

  if (action == InputAction::PAUSE && once) {
    auto scene = dynamic_cast<GameScene *>(world->getGame()->getScene());
    scene->pause(this->playerSession);
  }
}

bool Ship::isRecyclable() {
  return isDestroyed;
}

void Ship::renderTo(sf::RenderWindow *renderWindow) {
  renderShip(renderWindow);

  if (isThrusting) {
    renderThruster(renderWindow);
    isThrusting = false;
  }

  particleSystem.gravity = sf::Vector2f(-vel.x, -vel.y);
  particleSystem.remove();
  particleSystem.update();
  particleSystem.render();

  auto offset = vector::fromAngleDeg(rot) * -origin.x;

  auto sprite = particleSystem.getSprite();
  sprite.setPosition(pos.x + offset.x - 64, pos.y + offset.y - 64);
  renderWindow->draw(sprite);
}

Ship::Ship(WorldInterface *world, PlayerSession *playerSession)
    : Actor(world), particleSystem(128, 128) {
  this->playerSession = playerSession;
  points.emplace_back(20, 8);
  points.emplace_back(0, 0);
  points.emplace_back(0, 3);
  points.emplace_back(2, 3);
  points.emplace_back(2, 5);
  points.emplace_back(0, 5);
  points.emplace_back(0, 11);
  points.emplace_back(2, 11);
  points.emplace_back(2, 13);
  points.emplace_back(0, 13);
  points.emplace_back(0, 16);

  origin = sf::Vector2f(10, 8);

  auto size = points.size();

  shape.setPointCount(size);

  for (size_t i = 0; i < size; i++) {
    shape.setPoint(i, points[i]);
  }

  shape.setFillColor(fillColor);
  shape.setOutlineThickness(1.0F);
  shape.setOrigin(origin.x, origin.y);

  particleSystem.setDissolve(true);
  particleSystem.setDissolutionRate(30);
  particleSystem.setShape(Shape::CIRCLE);
}
