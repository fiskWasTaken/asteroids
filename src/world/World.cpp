//
// Created by fisk on 24/09/17.
//

#include "World.h"

void World::wrapObject(WorldObjectInterface *object) {
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

void World::checkCollision(AbstractWorldObject *a) {
  for (auto b: objects) {
    if (a != b) {
      collisionResult result = collisionModel.check(a, b);

      if (result.isCollision) {
        a->onCollision(b);
      }
    }
  }
}

void World::recycle() {
  std::set<AbstractWorldObject *>::iterator tmp;

  for (auto it = objects.begin(); it != objects.end();) {
    auto object = *it;

    if (object->isRecyclable()) {
      tmp = it;
      ++tmp;
      objects.erase(it);
      delete (object);
      it = tmp;
    } else {
      ++it;
    }
  }
}

void World::update() {
  for (auto object: objects) {
    wrapObject(object);
    checkCollision(object);
    object->update();
  }

  recycle();
}
