#pragma once

#include <set>
#include <collision/SATCollisionModel.h>
#include "collision/CollisionModelInterface.h"
#include "entities/AbstractWorldObject.h"
#include "GameInterface.h"
#include "WorldInterface.h"

class World : public WorldInterface {
 private:
  std::set<AbstractWorldObject *> objects;
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
    return objects.insert(object).second;
  }

  bool popObject(AbstractWorldObject *object) override {
    return objects.erase(object) != 0;
  }

  const std::set<AbstractWorldObject *> &getObjects() const {
    return objects;
  }

  GameInterface *getGame() override {
    return game;
  }

  void checkCollision(AbstractWorldObject *a);
  void recycle();

  ~World() {
    for (auto object: objects) {
      delete object;
    }
  }
};