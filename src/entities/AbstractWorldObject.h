#pragma once

#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>
#include <SFML/Graphics/Shape.hpp>
#include "WorldObjectClass.h"
#include "world/WorldInterface.h"
#include "WorldObjectInterface.h"

class WorldInterface;

class AbstractWorldObject : public WorldObjectInterface {
 protected:
  WorldInterface *world;

 public:
  virtual void update() = 0;
  virtual bool isRecyclable() = 0;

  /**
   * Invoked when this object is colliding with another object
   * This will be triggered on each frame in which there is a collision
   *
   * @param other the other object this object is colliding with
   */
  virtual void onCollision(AbstractWorldObject *other) {

  }

  explicit AbstractWorldObject(WorldInterface *world) {
    this->world = world;
    pos = sf::Vector2f(0, 0);
    vel = sf::Vector2f(0, 0);
    acc = sf::Vector2f(0, 0);
    rot = 0.0F;
  }
};
