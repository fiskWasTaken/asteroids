//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_WORLD_H
#define ASTEROIDS_WORLD_H

#include <set>
#include "CollisionModel.h"
#include "entities/AbstractWorldObject.h"

class AbstractWorldObject;

class World {
 private:
  std::set<AbstractWorldObject*> objects;
  double w;
  double h;
  CollisionModel collisionModel;

 public:
  World(double w, double h) {
    this->w = w;
    this->h = h;
    this->collisionModel = CollisionModel();
  }

  void wrapObject(AbstractWorldObject *object);

  void update();

  bool pushObject(AbstractWorldObject *object) {
    return objects.insert(object).second;
  }

  bool popObject(AbstractWorldObject *object) {
    return objects.erase(object) != 0;
  }

  const std::set<AbstractWorldObject *> &getObjects() const {
    return objects;
  }

  double getWidth() const {
    return w;
  }
  double getHeight() const {
    return h;
  }
  void checkCollision(AbstractWorldObject *a);
};

#endif //ASTEROIDS_WORLD_H
