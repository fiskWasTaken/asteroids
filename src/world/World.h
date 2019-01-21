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
  World(GameInterface *game, double w, double h);
  ~World();

  void update() override;

  double getWidth() const override { return w; }
  double getHeight() const override { return h; }

  void wrapObject(WorldObjectInterface *object) override;
  void containObject(WorldObjectInterface *object);

  bool push(AbstractWorldObject *object) override;
  bool pop(AbstractWorldObject *object) override;

  const std::vector<AbstractWorldObject *> &getObjects() const { return objects; }

  GameInterface *getGame() override { return game; }

  void recycle();
  void clear() { objects.clear(); }
};