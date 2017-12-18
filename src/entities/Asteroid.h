#pragma once

#include <entities/AbstractWorldObject.h>
#include <entities/Bullet.h>
#include <utility/shape.h>
#include <SFML/Graphics/ConvexShape.hpp>

class Asteroid : public AbstractWorldObject {
 private:
  float size;
  const sf::Color outlineColor = sf::Color(127, 127, 127);
  const sf::Color fillColor = sf::Color(255, 255, 255, 25);
  int health = 100;
  float rotSpeed = 0.1f;
  sf::ConvexShape shape;

 public:
  explicit Asteroid(WorldInterface *world, float size);

  WorldObjectClass getClass() override {
    return WorldObjectClass::ASTEROID;
  }

  bool isDestroyed() { return health <= 0; }
  void onDestroyed();

  int getMaxHealth() { return static_cast<int>(size); }
  int getScoreValue() { return static_cast<int>(size / 10); }
  int getHealth() { return health; }
  void takeDamage(int damage);
  bool isRecyclable() override;
  void onCollision(AbstractWorldObject *other) override;
  void renderTo(sf::RenderWindow *renderWindow) override;
  void update() override;

  void onBulletHit(Bullet *bullet);
  void onAsteroidHit(Asteroid *other);
  void onShipHit(Ship *other);
};


