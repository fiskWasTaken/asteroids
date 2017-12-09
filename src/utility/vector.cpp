//
// Created by fisk on 09/12/17.
//

#include <cmath>
#include "vector.h"

namespace vector {
sf::Vector2f getFromAngle(float angle) {
  float r = 3.14159265F / 180;
  return {std::cos(angle * r), std::sin(angle * r)};
}

float getLength(sf::Vector2f *vector) {
  return std::sqrt(vector->x * vector->x + vector->y * vector->y);
}

sf::Vector2f *normalise(sf::Vector2f *vector) {
  float length = getLength(vector);
  vector->x = vector->x / length;
  vector->y = vector->y / length;
  return vector;
}

sf::Vector2f *setLength(sf::Vector2f *vector, float length) {
  vector = normalise(vector);
  vector->x = vector->x * length;
  vector->y = vector->y * length;
  return vector;
}

sf::Vector2f *limit(sf::Vector2f *vector, float length) {
  auto current = getLength(vector);

  if (current > length) {
    vector = normalise(vector);
    vector->x *= length;
    vector->y *= length;
  }

  return vector;
}
}