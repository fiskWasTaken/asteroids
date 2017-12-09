//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_COLLISION_H
#define ASTEROIDS_COLLISION_H

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <entities/WorldObjectInterface.h>

class CollisionModelInterface {
 public:
  virtual bool check(WorldObjectInterface *a, WorldObjectInterface *b) = 0;
};

#endif //ASTEROIDS_COLLISION_H
