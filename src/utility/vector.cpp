//
// Created by fisk on 09/12/17.
//

#include <cmath>
#include "vector.h"

namespace vector {
float len(sf::Vector2f *vector) {
  return std::sqrt(vector->x * vector->x + vector->y * vector->y);
}

float dot(sf::Vector2f *a, sf::Vector2f *b) {
  return a->x * b->x + a->y * b->y;
}

sf::Vector2f rot(sf::Vector2f vector, float degrees) {
  float r = 3.14159265F / 180;
  sf::Vector2f out;
  out.x = vector.x * std::cos(r * degrees) - vector.y * std::sin(r * degrees);
  out.y = vector.x * std::sin(r * degrees) + vector.y * std::cos(r * degrees);
  return out;
}

sf::Vector2f fromAngle(float angle) {
  float r = 3.14159265F / 180;
  return {std::cos(angle * r), std::sin(angle * r)};
}

sf::Vector2f *normalise(sf::Vector2f *vector) {
  float length = len(vector);
  vector->x = vector->x / length;
  vector->y = vector->y / length;
  return vector;
}

sf::Vector2f *len(sf::Vector2f *vector, float length) {
  vector = normalise(vector);
  vector->x = vector->x * length;
  vector->y = vector->y * length;
  return vector;
}

sf::Vector2f *perpL(sf::Vector2f *vector) {
  float tmp = vector->x;
  vector->x = -vector->y;
  vector->y = tmp;
  return vector;
}

sf::Vector2f *perpR(sf::Vector2f *vector) {
  float tmp = vector->y;
  vector->y = -vector->x;
  vector->x = tmp;
  return vector;
}

sf::Vector2f *limit(sf::Vector2f *vector, float length) {
  auto current = len(vector);

  if (current > length) {
    vector = normalise(vector);
    vector->x *= length;
    vector->y *= length;
  }

  return vector;
}
}