//
// Created by fisk on 11/12/17.
//

#ifndef ASTEROIDS_BASEASTEROID_H
#define ASTEROIDS_BASEASTEROID_H

#include <entities/AbstractWorldObject.h>
class AsteroidBase : public AbstractWorldObject {
 protected:
  int health = 100;

 public:
  WorldObjectClass getClass() override {
    return WorldObjectClass::ASTEROID;
  }

  explicit AsteroidBase(WorldInterface *world) : AbstractWorldObject(world) {
    this->health = this->getMaxHealth();
  }

  inline int getHealth() {
    return health;
  }

  inline int getMaxHealth() {
    return 100;
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
};

#endif //ASTEROIDS_BASEASTEROID_H
