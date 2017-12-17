#include <cmath>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <scenes/GameScene.h>
#include <caca_conio.h>
#include "Bullet.h"
#include "../utility/vector.h"
#include "TemporaryParticle.h"

void Ship::fireBullet() {
  auto thisRot = vector::fromAngle(rot);
  auto velocity = thisRot * 5.0F;
  auto bullet = new Bullet(world, this->getPlayerSession());

  bullet->pos.x = pos.x + thisRot.x * 10;
  bullet->pos.y = pos.y + thisRot.y * 10;
  bullet->vel = velocity + vel;
  bullet->rot = rot;

  vel.x -= bullet->vel.x / 100;
  vel.y -= bullet->vel.y / 100;

  world->pushObject(bullet);
}

void Ship::fireAltWeapon() {
  for (int i = 0; i < 10; i++) {
    auto thisRot = vector::fromAngle(rot + i * 2 - 10);
    auto velocity = thisRot * 5.0F;
    auto bullet = new Bullet(world, this->getPlayerSession());
    bullet->pos.x = pos.x + thisRot.x * 10;
    bullet->pos.y = pos.y + thisRot.y * 10;
    bullet->vel = velocity + vel;
    bullet->rot = rot;
    world->pushObject(bullet);
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

  vel *= 0.99F;

  if (isOnInvincibilityCooldown()) {
    invincibilityTimer--;
  }
}

void Ship::onDestroyed() {
  auto scene = dynamic_cast<GameScene *>(world->getGame()->getScene());
  isDestroyed = true;
  scene->onShipDestroyed(playerSession);

  auto explosion = new ParticleSystem(128, 128);
  explosion->setColor(playerSession->getPlayer()->getColor());
  explosion->setParticleSpeed(40);
  explosion->fuel(50);
  explosion->setDissolve(true);
  explosion->setDissolutionRate(10);
  explosion->setShape(Shape::CIRCLE);
  auto emitter = new TemporaryParticle(world, explosion);
  emitter->pos.x = pos.x;
  emitter->pos.y = pos.y;
  world->pushObject(emitter);
}

void Ship::onAction(InputAction action, bool once) {
  if (action == InputAction::ACCELERATE) {
    // get the current speed
    auto target = vector::fromAngle(rot) * MAX_SPEED;
    auto diff = target - acc;

    diff *= 0.10F;

    acc.x = diff.x;
    acc.y = diff.y;

//    printf("pos: %.2f, %.2f vel: %.2f, %.2f acc: %.2f, %.2f\n", pos.x, pos.y, vel.x, vel.y, acc.x, acc.y);
    isThrusting = true;
  }

  if (action == InputAction::BRAKE) {
    // really we're just going in reverse
    auto target = vector::fromAngle(rot) * MAX_SPEED;
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

  particleSystem.setGravity(-vel.x, -vel.y);
  particleSystem.remove();
  particleSystem.update();
  particleSystem.render();

  auto offset = vector::fromAngle(rot) * -origin.x;

  auto sprite = particleSystem.getSprite();
  sprite.setPosition(pos.x + offset.x - 64, pos.y + offset.y - 64);
  renderWindow->draw(sprite);
}

void Ship::renderShip(sf::RenderWindow *renderWindow) {
  bool invisible = (invincibilityTimer / 3 % 2 != 0);

  if (invisible) {
    shape.setOutlineColor(sf::Color(50, 50, 50));
  } else {
    shape.setOutlineColor(getPlayerSession()->getPlayer()->getColor());
  }

  shape.setRotation(rot);
  shape.setPosition(pos);
  renderWindow->draw(shape);
}

void Ship::renderThruster(sf::RenderWindow *renderWindow) {
  particleSystem.fuel(1);
}

void Ship::onCollision(AbstractWorldObject *other) {
  if (other->getClass() == WorldObjectClass::SHIP) {
    onShipHit(dynamic_cast<Ship *>(other));
  }
}

void Ship::onShipHit(Ship *other) {
  // bounce
  auto diff = vel - other->vel;
  diff.x /= 1.1;
  diff.y /= 1.1;

  vel -= diff;
  other->vel += diff;
}