#include <SFML/System/Vector2.hpp>
#include <vector>
#include <utility/vector.h>

struct projection
{
  float min, max;

  float hasOverlap(projection& other) {
    return max > other.min || min > other.max;
  }

  inline float getOverlap(projection& other)
  {
    return max > other.min ? max - other.min : other.max - min;
  }
};

inline projection getProjection(sf::Vector2f axis, std::vector<sf::Vector2f> points)
{
  auto size = points.size();
  float min = vector::dot(axis, points[0]);
  float max = min;

  for (int i = 0; i < size; i++)
  {
    float p = vector::dot(axis, points[i]);

    if (p < min)
    {
      min = p;
    }
    else if (p > max)
    {
      max = p;
    }
  }

  return {min, max};
}