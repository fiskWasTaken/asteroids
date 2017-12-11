#pragma once

#include "CollisionModelInterface.h"

std::vector<sf::Vector2f> getOffsetPoints(WorldObjectInterface *object);

class SATCollisionModel : public CollisionModelInterface {
 public:
  collision_result_t check(WorldObjectInterface *a, WorldObjectInterface *b) override;
};