#pragma once

#include <utility/shape.h>
#include "AbstractWorldObject.h"
#include "Ship.h"
#include <SFML/Graphics/ConvexShape.hpp>

class PlayerSession;

class Bullet : public AbstractWorldObject {
 private:
  sf::ConvexShape shape;
  int lifetime = 80;
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
  }

  PlayerSession *getOwner() const {
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