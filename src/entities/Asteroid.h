#pragma once

#include <entities/AbstractWorldObject.h>
#include <entities/Bullet.h>

class Asteroid : public AbstractWorldObject {
 private:
  float size;
  const sf::Color outlineColor = sf::Color(244, 167, 66);
  int health = 100;
  float rotSpeed = 0.1f;

 public:
  explicit Asteroid(WorldInterface *world, float size) : AbstractWorldObject(world) {
    this->size = size;
    rotSpeed = (-5 + float(random() % 10)) / 10;
    points.emplace_back(size * 0.5, 0);
    points.emplace_back(size, size * 0.25);
    points.emplace_back(size, size * 0.75);
    points.emplace_back(size * 0.5, size);
    points.emplace_back(0, size * 0.75);
    points.emplace_back(0, size * 0.25);
    origin = sf::Vector2f(size / 2, size / 2);
    this->health = this->getMaxHealth();
  }

  WorldObjectClass getClass() override {
    return WorldObjectClass::ASTEROID;
  }

  inline int getMaxHealth() {
    return static_cast<int>(size);
  }

  inline int getScoreValue() {
    return static_cast<int>(size / 10);
  }

  void onDestroyed();

  inline int getHealth() {
    return health;
  }

  inline bool isDestroyed() {
    return health <= 0;
  }

  inline void takeDamage(int damage) {
    health -= damage;

    if (health <= 0) {
      health = 0;
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


