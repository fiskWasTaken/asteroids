//
// Created by fisk on 21/09/17.
//

#ifndef ASTEROIDS_WORLDOBJECT_H
#define ASTEROIDS_WORLDOBJECT_H

#include <SFML/System/Vector2.hpp>
#include <utility>
#include <vector>
#include "WorldObjectClass.h"
#include "../World.h"

typedef std::pair<sf::Vector2f, sf::Vector2f> BoundingBox;

class World;

class WorldObject {
 protected:
  double width = 1;
  double height = 1;

 public:
  sf::Vector2f pos;
  sf::Vector2f vel;
  sf::Vector2f acc;
  float rot;

  static const WorldObjectClass OBJECT_CLASS = WorldObjectClass::NONE;

  virtual void update(World *world) {

  }

  virtual bool isRecyclable() = 0;

  /**
   * Invoked when this object is colliding with another object
   * This will be triggered on each frame in which there is a collision
   *
   * @param other the other object this object is colliding with
   */
  virtual void onCollision(WorldObject *other) {

  }

  explicit WorldObject() {
    pos = sf::Vector2f(0, 0);
    vel = sf::Vector2f(0, 0);
    acc = sf::Vector2f(0, 0);
    rot = 0.0F;
  }

  inline double getWidth() const { return width; }
  inline void setWidth(double width) { WorldObject::width = width; }
  inline double getHeight() const { return height; }
  inline void setHeight(double height) { WorldObject::height = height; }

  BoundingBox getBoundingBox() {
    return BoundingBox(
        sf::Vector2f((float) (pos.x - width / 2), (float) (pos.y - height / 2)),
        sf::Vector2f((float) (pos.x + width / 2), (float) (pos.y + height / 2))
    );
  }

  std::vector<sf::Vector2f> getPoints() {
    std::vector<sf::Vector2f> vector;

    vector.push_back(sf::Vector2f((float) (pos.x - width / 2), (float) (pos.y - height / 2)));
    vector.push_back(sf::Vector2f((float) (pos.x + width / 2), (float) (pos.y + height / 2)));
    vector.push_back(sf::Vector2f((float) (pos.x + width / 2), (float) (pos.y - height / 2)));
    vector.push_back(sf::Vector2f((float) (pos.x - width / 2), (float) (pos.y + height / 2)));

    return vector;
  }
};

#endif //ASTEROIDS_WORLDOBJECT_H
