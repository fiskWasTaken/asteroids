#pragma once

#include <utility/shape.h>
#include "AbstractWorldObject.h"
#include "Ship.h"

class PlayerSession;

class Bullet : public AbstractWorldObject {
  int lifetime = 100;
  /*
   * we use the PlayerSession and not the Ship
   * as the ship is prone to be garbage collected,
   * leaving it open to segfault if a bullet scores
   * a kill after death
   */
  PlayerSession *owner;

 public:
  WorldObjectClass getClass() override {
    return WorldObjectClass::BULLET;
  }

  explicit Bullet(WorldInterface *world, PlayerSession *owner) : AbstractWorldObject(world) {
    points = shape::generateShape(3, 2);
    origin = sf::Vector2f(1, 1);
    this->owner = owner;
  }

  inline PlayerSession *getOwner() const {
    return this->owner;
  }

  bool isRecyclable() override {
    return lifetime <= 0;
  }

  void update() override {
    pos += vel;
    lifetime--;
  };

  void setLifetime(int lifetime);

  void renderTo(sf::RenderWindow *renderWindow) override;

  const sf::Color outlineColor = sf::Color(173, 173, 173);
};