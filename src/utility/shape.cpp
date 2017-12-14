#include "shape.h"
#include "vector.h"

namespace shape {
std::vector<sf::Vector2f> generateShape(unsigned long points, float size, float noise) {
  auto vectors = std::vector<sf::Vector2f>();

  for (int i = 0; i < points; i++) {
    float angle = (360.0F / points) * i;
    auto vec = vector::len(vector::fromAngle(angle), size / 2);
    // Move vector so shape is aligned to 0,0
    vec.x += size / 2;
    vec.y += size / 2;
    vectors.push_back(vec);
  }

  return vectors;
}
}
