#pragma once

#include <entities/AbstractWorldObject.h>
#include <entities/Bullet.h>
#include <utility/shape.h>
#include <SFML/Graphics/ConvexShape.hpp>

class Asteroid : public AbstractWorldObject {
 private:
  float size;
  const sf::Color outlineColor = sf::Color(127, 127, 127);
  int health = 100;
  float rotSpeed = 0.1f;
  sf::ConvexShape shape;

 public:
  explicit Asteroid(WorldInterface *world, float size) : AbstractWorldObject(world) {
    this->size = size;
    rotSpeed = (-5 + float(random() % 10)) / 10;

    auto edges = 5 + size / 20;
    points = shape::generateShape(static_cast<unsigned long>(edges), size);
    origin = sf::Vector2f(size / 2, size / 2);
    health = this->getMaxHealth();

    shape.setPointCount(points.size());

    for (size_t i = 0; i < points.size(); i++) {
      shape.setPoint(i, points[i]);
    }

    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(outlineColor);
    shape.setOutlineThickness(1.0F);
    shape.setOrigin(origin.x, origin.y);
  }

  WorldObjectClass getClass() override {
    return WorldObjectClass::ASTEROID;
  }

  int getMaxHealth() {
    return static_cast<int>(size);
  }

  int getScoreValue() {
    return static_cast<int>(size / 10);
  }

  void onDestroyed();

  int getHealth() {
    return health;
  }

  bool isDestroyed() {
    return health <= 0;
  }

  void takeDamage(int damage) {
    // guards against triggering onDestroyed() multiple times if hit again before entity recycle
    if (health > 1) {
      health -= damage;

      if (health <= 0)
        this->onDestroyed();
    }
  }

  bool isRecyclable() override;
  void onCollision(AbstractWorldObject *other) override;
  void renderTo(sf::RenderWindow *renderWindow) override;
  void update() override;
  void onBulletHit(Bullet *bullet);
  void onAsteroidHit(Asteroid *other);
  void onShipHit(Ship *other);
};


