//
// Created by fisk on 09/12/17.
//

#ifndef ASTEROIDS_SATCOLLISIONMODEL_H
#define ASTEROIDS_SATCOLLISIONMODEL_H

#include "CollisionModelInterface.h"

class SATCollisionModel : public CollisionModelInterface {
 public:
  bool check(WorldObjectInterface *a, WorldObjectInterface *b) override;
};

#endif //ASTEROIDS_SATCOLLISIONMODEL_H
