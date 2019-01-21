#pragma once

#include <utility/shape.h>
#include "AbstractWorldObject.h"
#include "Ship.h"
#include <SFML/Graphics/ConvexShape.hpp>

class Bullet : public AbstractWorldObject {
 private:
  ParticleSystem particleSystem;
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
  explicit Bullet(WorldInterface *world, PlayerSession *owner);
  std::string getClass() override { return "bullet"; }
  PlayerSession *getOwner() const { return this->owner; }
  bool isRecyclable() override { return lifetime <= 0; }

  void update() override {
    pos += vel;
    lifetime--;
  };

  void setLifetime(int lifetime);
  void renderTo(sf::RenderWindow *renderWindow) override;
  const sf::Color outlineColor = sf::Color(150, 150, 150);
};