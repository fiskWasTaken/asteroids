#pragma once

#include <algorithm>
#include <set>
#include <collision/SATCollisionModel.h>
#include "collision/CollisionModelInterface.h"
#include "entities/AbstractWorldObject.h"
#include "GameInterface.h"
#include "WorldInterface.h"

class World : public WorldInterface {
 private:
  std::vector<AbstractWorldObject *> objects;
  double w;
  double h;
  SATCollisionModel collisionModel;
  GameInterface *game;

 public:
  World(GameInterface *game, double w, double h) {
    this->game = game;
    this->w = w;
    this->h = h;
    this->collisionModel = SATCollisionModel();
    objects.reserve(2048);
  }

  void update() override;

  double getWidth() const override {
    return w;
  }

  double getHeight() const override {
    return h;
  }

  void wrapObject(WorldObjectInterface *object) override;

  bool pushObject(AbstractWorldObject *object) override {
    objects.push_back(object);
    return true;
  }

  bool popObject(AbstractWorldObject *object) override {
    objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
    return true;
  }

  const std::vector<AbstractWorldObject *> &getObjects() const {
    return objects;
  }

  GameInterface *getGame() override {
    return game;
  }

  void recycle();

  ~World() {
    for (auto object: objects) {
      delete object;
    }
  }
};