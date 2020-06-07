#pragma once
#include "CollisionModelInterface.h"
#include <utility/vector.h>
#include "projection.h"
#include <optional>

inline std::vector<sf::Vector2f> getNormals(std::vector<sf::Vector2f> points)
{
  auto size = points.size();
  std::vector<sf::Vector2f> out;
  out.reserve(size);

  for (int i = 0; i < size; i++)
  {
    auto curr = points[i];
    auto next = points[i + 1 == size ? 0 : i + 1];
    auto edge = curr - next;

    out.push_back(vector::perpL(edge));
  }
  return out;
}

inline std::vector<sf::Vector2f> getOffsetPoints(IActor *object)
{
  auto points = object->points;
  std::vector<sf::Vector2f> offsets;
  offsets.reserve(points.size());

  for (auto point : points)
  {
    offsets.push_back(vector::rot(point - object->origin, object->rot) + object->pos);
  }

  return offsets;
}
class SATCollisionModel : public CollisionModelInterface
{
public:
  collision_result_t check(IActor *a, IActor *b)
  {
    auto aOffsets = getOffsetPoints(a);
    auto bOffsets = getOffsetPoints(b);
    sf::Vector2f mtv;
    float mtvLen = -1;

    for (auto axis : getNormals(aOffsets))
    {
      auto p1 = getProjection(axis, aOffsets);
      auto p2 = getProjection(axis, bOffsets);

      if (!p1.hasOverlap(p2))
      {
        return {
            false,
            mtv};
      }
      else
      {
        float o = p1.getOverlap(p2);
        if (mtvLen == -1 || o < mtvLen)
        {
          mtvLen = o;
          mtv = axis;
        }
      }
    }

    for (auto axis : getNormals(bOffsets))
    {
      auto p1 = getProjection(axis, aOffsets);
      auto p2 = getProjection(axis, bOffsets);

      if (!p1.hasOverlap(p2))
      {
        return {
            false,
            mtv};
      }
      else
      {
        float o = p1.getOverlap(p2);
        if (mtvLen == -1 || o < mtvLen)
        {
          mtvLen = o;
          mtv = axis;
        }
      }
    }

    return {
        true,
        vector::len(mtv, mtvLen)};
  }
};