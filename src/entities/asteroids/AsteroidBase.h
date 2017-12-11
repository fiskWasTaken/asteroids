#pragma once

#include <entities/AbstractWorldObject.h>

class Bullet;

class AsteroidBase : public AbstractWorldObject {
 protected:
  int health = 100;

 public:
  WorldObjectClass getClass() override {
    return WorldObjectClass::ASTEROID;
  }

  explicit AsteroidBase(WorldInterface *world) : AbstractWorldObject(world) {
  }

  inline int getHealth() {
    return health;
  }

  virtual int getMaxHealth() = 0;

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
};