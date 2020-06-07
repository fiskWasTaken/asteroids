#pragma once

#include <utility/shape.h>
#include <utility/vector.h>
#include "Actor.h"
#include "Ship.h"
#include <SFML/Graphics/ConvexShape.hpp>
#include <player/PlayerSession.h>

class Bullet : public Actor
{
private:
  ParticleSystem particles;
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
  sf::Color color;
  
  explicit Bullet(WorldInterface *world, PlayerSession *owner) : Actor(world), particles(128, 128)
  {
    points = shape::generateShape(3, 1);
    origin = sf::Vector2f(1, 1);
    this->owner = owner;

    // create an empty shape
    auto size = points.size();

    shape.setPointCount(size);

    for (size_t i = 0; i < size; i++)
    {
      shape.setPoint(i, points[i]);
    }

    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(outlineColor);
    shape.setOutlineThickness(1.0F);
    shape.setOrigin(origin.x, origin.y);

    if (owner != nullptr) {
      color = owner->player->getColor();
      particles.setColor(color);
    }
    
    particles.setDissolve(true);
    particles.setDissolutionRate(40);
    particles.setShape(Shape::CIRCLE);
  }

  std::string getClass() override { return "bullet"; }
  PlayerSession *getOwner() const { return this->owner; }
  bool isRecyclable() override { return lifetime <= 0; }

  void update() override
  {
    pos += vel;
    lifetime--;
  };

  void setLifetime(int lifetime)
  {
    this->lifetime = lifetime;
  }
  void renderTo(sf::RenderWindow *renderWindow) override
  {
    shape.setPosition(pos);
    shape.setRotation(rot);

    renderWindow->draw(shape);

    particles.fuel(1);
    particles.gravity = sf::Vector2f(-vel.x, -vel.y);
    particles.remove();
    particles.update();
    particles.render();

    auto offset = vector::fromAngleDeg(rot) * -origin.x;

    auto sprite = particles.getSprite();
    sprite.setPosition(pos.x + offset.x - 64, pos.y + offset.y - 64);
    renderWindow->draw(sprite);
  }

  const sf::Color outlineColor = sf::Color(150, 150, 150);
};