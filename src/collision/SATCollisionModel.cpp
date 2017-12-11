#include <utility/vector.h>
#include "SATCollisionModel.h"

struct projection {
  float min;
  float max;
};

inline std::vector<sf::Vector2f> getNormals(std::vector<sf::Vector2f> points) {
  auto size = points.size();
  std::vector<sf::Vector2f> out;

  for (int i = 0; i < size; i++) {
    auto curr = points[i];
    auto next = points[i + 1 == size ? 0 : i + 1];
    auto edge = curr - next;

    out.push_back(vector::perpL(edge));
  }
  return out;
}

inline projection getProjection(sf::Vector2f axis, std::vector<sf::Vector2f> points) {
  auto size = points.size();
  float min = vector::dot(axis, points[0]);
  float max = min;

  for (int i = 0; i < size; i++) {
    float p = vector::dot(axis, points[i]);

    if (p < min) {
      min = p;
    } else if (p > max) {
      max = p;
    }
  }

  return {min, max};
}

inline bool overlap(projection a, projection b) {
  return a.max > b.min || a.min > b.max;
}

inline float getOverlap(projection a, projection b) {
  return a.max > b.min ? a.max - b.min : b.max - a.min;
}

std::vector<sf::Vector2f> getOffsetPoints(WorldObjectInterface *object) {
  auto points = object->points;
  std::vector<sf::Vector2f> offsets;

  for (auto point : points) {
    offsets.push_back(vector::rot(point - object->origin, object->rot) + object->pos);
  }

  return offsets;
}

collision_result_t SATCollisionModel::check(WorldObjectInterface *a, WorldObjectInterface *b) {
  auto aOffsets = getOffsetPoints(a);
  auto bOffsets = getOffsetPoints(b);
  sf::Vector2f mtv;
  float mtvLen = -1;

  for (auto axis: getNormals(aOffsets)) {
    auto p1 = getProjection(axis, aOffsets);
    auto p2 = getProjection(axis, bOffsets);

    if (!overlap(p1, p2)) {
      return {
          false,
          mtv
      };
    } else {
      float o = getOverlap(p1, p2);
      if (mtvLen == -1 || o < mtvLen) {
        mtvLen = o;
        mtv = axis;
      }
    }
  }

  for (auto axis: getNormals(bOffsets)) {
    auto p1 = getProjection(axis, aOffsets);
    auto p2 = getProjection(axis, bOffsets);

    if (!overlap(p1, p2)) {
      return {
          false,
          mtv
      };
    } else {
      float o = getOverlap(p1, p2);
      if (mtvLen == -1 || o < mtvLen) {
        mtvLen = o;
        mtv = axis;
      }
    }
  }

  return {
      true,
      vector::len(mtv, mtvLen)
  };
}