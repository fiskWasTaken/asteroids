//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_WORLDOBJECT_H
#define ASTEROIDS_WORLDOBJECT_H

#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>
#include <SFML/Graphics/Shape.hpp>
#include "WorldObjectClass.h"
#include "../World.h"
#include "WorldObjectInterface.h"

typedef std::pair<sf::Vector2f, sf::Vector2f> BoundingBox;

class World;

class AbstractWorldObject : public WorldObjectInterface {
 protected:
  World *world;

 public:
  virtual WorldObjectClass getClass() {
    return WorldObjectClass::NONE;
  }

  virtual void update() = 0;
  virtual sf::Drawable *getDrawable() = 0;
  virtual bool isRecyclable() = 0;

  /**
   * Invoked when this object is colliding with another object
   * This will be triggered on each frame in which there is a collision
   *
   * @param other the other object this object is colliding with
   */
  virtual void onCollision(AbstractWorldObject *other) {

  }

  explicit AbstractWorldObject(World *world) {
    this->world = world;
    pos = sf::Vector2f(0, 0);
    vel = sf::Vector2f(0, 0);
    acc = sf::Vector2f(0, 0);
    rot = 0.0F;
  }
};

#endif //ASTEROIDS_WORLDOBJECT_H
