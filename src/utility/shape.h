#pragma once

#include <SFML/System.hpp>
#include <vector>
#include "vector.h"

namespace shape {
/**
 * Generates a shape.
 * @param points the number of points in the shape
 * @param size the size of the shape
 * @param noise potential difference in point placement (not yet implemented)
 * @return A list of shape vectors.
 */
inline std::vector<sf::Vector2f> generateShape(unsigned long points, float size, float noise = 0) {
  std::vector<sf::Vector2f> vectors;
  vectors.reserve(points);

  for (int i = 0; i < points; i++) {
    float angle = (360.0F / points) * i;
    auto vec = vector::len(vector::fromAngleDeg(angle), size / 2);
    // Move vector so shape is aligned to 0,0
    vec.x += size / 2;
    vec.y += size / 2;
    vectors.push_back(vec);
  }

  return vectors;
}
};


