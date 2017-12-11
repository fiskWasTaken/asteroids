//
// Created by fisk on 11/12/17.
//

#include "MediumAsteroid.h"
#include "SmallAsteroid.h"

void MediumAsteroid::onDestroyed() {
  auto ast1 = new SmallAsteroid(world);
  ast1->pos.x = pos.x - 10;
  ast1->pos.y = pos.y;
  ast1->vel.x = -3.0f;
  ast1->vel.y = 3.0f;

  world->pushObject(ast1);

  auto ast2 = new SmallAsteroid(world);
  ast2->pos.x = pos.x + 10;
  ast2->pos.y = pos.y;
  ast2->vel.x = 3.0f;
  ast2->vel.y = -3.0f;

  world->pushObject(ast2);

}