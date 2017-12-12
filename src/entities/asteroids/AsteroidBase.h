#pragma once

#include <entities/AbstractWorldObject.h>

class Bullet;

class AsteroidBase : public AbstractWorldObject {
 protected:
  const sf::Color outlineColor = sf::Color(244, 167, 66);
  int health = 100;
  float rotSpeed = 0.1f;

 public:
  WorldObjectClass getClass() override {
    return WorldObjectClass::ASTEROID;
  }

  explicit AsteroidBase(WorldInterface *world) : AbstractWorldObject(world) {
    rotSpeed = (-5 + float(random() % 10)) / 10;
  }

  inline int getHealth() {
    return health;
  }

  virtual int getMaxHealth() = 0;
  virtual int getScoreValue() = 0;

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

  virtual void onDestroyed() = 0;
  bool isRecyclable() override;
  void onCollision(AbstractWorldObject *other) override;
  void renderTo(sf::RenderWindow *renderWindow) override;
  void update() override;
  void onBulletHit(Bullet *bullet);
  void onAsteroidHit(AsteroidBase *other);
};