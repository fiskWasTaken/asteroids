//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_COLLISION_H
#define ASTEROIDS_COLLISION_H

#include <SFML/System/Vector2.hpp>
#include <vector>
#include <entities/WorldObjectInterface.h>

class CollisionModel {
 public:
  bool check(WorldObjectInterface *a, WorldObjectInterface *b);
};

#endif //ASTEROIDS_COLLISION_H
