#pragma once

#include <entities/IActor.h>
#include <entities/Actor.h>

class IGame;
class Actor;

class WorldInterface {
 public:
  virtual double getWidth() const = 0;
  virtual double getHeight() const = 0;

  virtual void wrapObject(IActor *object) = 0;

  virtual bool push(Actor *object) = 0;

  virtual bool pop(Actor *object) = 0;

  virtual void update() = 0;

  virtual std::vector<Actor *> getActors() = 0;

  virtual IGame *getGame() = 0;

};