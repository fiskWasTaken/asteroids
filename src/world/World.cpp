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

void World::containObject(WorldObjectInterface *object) {
  auto pos = &object->pos;
  auto vel = &object->vel;

  if (pos->x < 0) {
    pos->x = 0;
    vel->x = -vel->x;
  } else if (pos->x > w) {
    pos->x = w;
    vel->x = -vel->x;
  }

  if (pos->y < 0) {
    pos->y = 0;
    vel->y = -vel->y;
  } else if (pos->y > h) {
    pos->y = h;
    vel->y = -vel->y;
  }

}

void World::recycle() {
  auto it = objects.begin();

  while (it != objects.end()) {

    if ((*it)->isRecyclable()) {
      it = objects.erase(it);
    } else {
      ++it;
    }
  }
}

void World::update() {
  for (auto object: objects) {
    wrapObject(object);
    object->update();
  }

  auto size = objects.size();

  for (int a = 0; a < size; a++) {
    if (objects[a]->points.empty()) {
      continue;
    }

    for (int b = a + 1; b < size; b++) {
      if (objects[b]->points.empty()) {
        continue;
      }

      collision_result_t result = collisionModel.check(objects[a], objects[b]);

      if (result.isCollision) {
        objects[a]->onCollision(objects[b]);
        objects[b]->onCollision(objects[a]);

        auto offset = sf::Vector2f(result.mtv.x / 100, result.mtv.y / 100);

        objects[a]->pos -= offset;
        objects[b]->pos += offset;
      }
    }
  }

  recycle();
}
