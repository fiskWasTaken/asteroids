#include <cmath>
#include "vector.h"

namespace vector {
float len(const sf::Vector2f vector) {
  return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

float rot(const sf::Vector2f vector) {
  return float(atan2(vector.y, vector.x)) * 180 / 3.14159265F;
}

float dot(const sf::Vector2f a, const sf::Vector2f b) {
  return a.x * b.x + a.y * b.y;
}

sf::Vector2f rot(const sf::Vector2f vector, float degrees) {
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

sf::Vector2f nor(const sf::Vector2f vector) {
  float length = len(vector);

  if (length == 0) {
    return {0, 0};
  }

  return {vector.x / length, vector.y / length};
}

sf::Vector2f len(const sf::Vector2f vector, float length) {
  auto out = nor(vector);
  return {out.x * length, out.y * length};
}

sf::Vector2f perpL(const sf::Vector2f vector) {
  return {-vector.y, vector.x};
}

sf::Vector2f perpR(const sf::Vector2f vector) {
  return {vector.y, -vector.x};
}

sf::Vector2f limit(sf::Vector2f vector, float length) {
  auto current = len(vector);

  if (current > length) {
    vector = nor(vector);
    vector.x *= length;
    vector.y *= length;
  }

  return vector;
}
}