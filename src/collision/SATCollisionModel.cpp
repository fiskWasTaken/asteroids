//
// Created by fisk on 09/12/17.
//

#include <utility/vector.h>
#include "SATCollisionModel.h"

struct projection {
  float min;
  float max;
};

std::vector<sf::Vector2f> getNormals(std::vector<sf::Vector2f> points) {
  auto size = points.size();
  std::vector<sf::Vector2f> out;

  for (int i = 0; i < size; i++) {
    auto curr = points[i];
    auto next = points[i + 1 == size ? 0 : i + 1];
    auto edge = curr - next;

    out.push_back(*vector::perpL(&edge));
  }
  return out;
}

projection getProjection(sf::Vector2f axis, std::vector<sf::Vector2f> points) {
  auto size = points.size();
  float min = vector::dot(&axis, &points[0]);
  float max = min;

  for (int i = 0; i < size; i++) {
    float p = vector::dot(&axis, &points[i]);

    if (p < min) {
      min = p;
    } else if (p > max) {
      max = p;
    }
  }

  return {min, max};
}

bool overlap(projection a, projection b) {
  return a.max > b.min || a.min > b.max;
}

// todo: actually offset the object points with its position...
std::vector<sf::Vector2f> getOffsetPoints(WorldObjectInterface *object) {
  auto points = object->points;
  std::vector<sf::Vector2f> offsets;

  for (auto point : points) {
    offsets.push_back(point + object->pos);
  }

  return offsets;
}

bool SATCollisionModel::check(WorldObjectInterface *a, WorldObjectInterface *b) {
  auto aOffsets = getOffsetPoints(a);
  auto bOffsets = getOffsetPoints(b);

  auto aAxes = getNormals(aOffsets);
  auto bAxes = getNormals(bOffsets);

  for (auto axis: aAxes) {
    auto p1 = getProjection(axis, aOffsets);
    auto p2 = getProjection(axis, bOffsets);

    if (!overlap(p1, p2)) {
      return false;
    }
  }

  for (auto axis: bAxes) {
    auto p1 = getProjection(axis, aOffsets);
    auto p2 = getProjection(axis, bOffsets);

    if (!overlap(p1, p2)) {
      return false;
    }
  }

  printf("Collision detected\n");

  return true;
}