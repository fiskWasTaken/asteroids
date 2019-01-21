#pragma once

#include <entities/WorldObjectInterface.h>
#include <entities/AbstractWorldObject.h>

class GameInterface;
class AbstractWorldObject;

class WorldInterface {
 public:
  virtual double getWidth() const = 0;
  virtual double getHeight() const = 0;

  virtual void wrapObject(WorldObjectInterface *object) = 0;

  virtual bool push(AbstractWorldObject *object) = 0;

  virtual bool pop(AbstractWorldObject *object) = 0;

  virtual void update() = 0;

  virtual GameInterface *getGame() = 0;
};