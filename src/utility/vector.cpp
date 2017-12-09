//
// Created by fisk on 09/12/17.
//

#include "vector.h"
#include <cmath>

namespace vector {
sf::Vector2f getFromAngle(float angle) {
  float r = 3.14159265F / 180;
  return {(float) cos(angle * r), (float) sin(angle * r)};
}

float len(sf::Vector2f vector) {
  return sqrt(vector.x * vector.x + vector.y * vector.y);
}
}