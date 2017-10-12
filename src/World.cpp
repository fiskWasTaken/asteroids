//
// Created by fisk on 24/09/17.
//

#include "World.h"

void World::wrapObject(WorldObject *object) {
  auto pos = &object->pos;

  if (pos->x < 0)
    pos->x += w;
  else if (pos->x > w)
    pos->x -= w;

  if (pos->y < 0)
    pos->y += h;
  else if (pos->y > h)
    pos->y -= h;
}

void World::checkCollision(WorldObject *a) {
  auto points_a = a->getPoints();

  for (auto b: objects) {
    if (b == a)
      continue;

    auto points_b = b->getPoints();

    bool result = collisionModel.check(points_a, points_b);

    if (result) {
      a->onCollision(b);
    }
  }
}

void World::update() {
  for (auto object: objects) {
    wrapObject(object);
    checkCollision(object);
    object->update(this);
  }

  std::set<WorldObject*>::iterator tmp;

  for (auto it = objects.begin(); it != objects.end();) {
    auto object = *it;

    if (object->isRecyclable()) {
      tmp = it;
      ++tmp;
      objects.erase(it);
      delete(object);
      it = tmp;
    } else {
      ++it;
    }
  }
}
