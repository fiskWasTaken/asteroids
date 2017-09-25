//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_WORLD_H
#define ASTEROIDS_WORLD_H

#include <entities/WorldObject.h>
#include <set>
#include "Collision.h"

class World {
 private:
  std::set<WorldObject*> objects;
  double w;
  double h;
  Collision collision;

 public:
  World(double w, double h) {
    this->w = w;
    this->h = h;
    this->collision = Collision();
  }

  void wrapObject(WorldObject *object);

  void update();

  bool pushObject(WorldObject *object) {
    return objects.insert(object).second;
  }

  bool popObject(WorldObject *object) {
    return objects.erase(object) != 0;
  }

  const std::set<WorldObject *> &getObjects() const {
    return objects;
  }

  double getWidth() const {
    return w;
  }
  double getHeight() const {
    return h;
  }
  void checkCollision(WorldObject *a);
};

#endif //ASTEROIDS_WORLD_H
