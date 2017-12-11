//
// Created by fisk on 09/12/17.
//

#ifndef ASTEROIDS_SATCOLLISIONMODEL_H
#define ASTEROIDS_SATCOLLISIONMODEL_H

#include "CollisionModelInterface.h"

std::vector<sf::Vector2f> getOffsetPoints(WorldObjectInterface *object);

class SATCollisionModel : public CollisionModelInterface {
 public:
  collisionResult check(WorldObjectInterface *a, WorldObjectInterface *b) override;
};

#endif //ASTEROIDS_SATCOLLISIONMODEL_H
