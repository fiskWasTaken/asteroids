#pragma once

#include <cmath>
#include <SFML/System/Vector2.hpp>

/**
 * All setter functions take a reference and return the reference for chaining
 */
namespace vector {
  inline float len(const sf::Vector2f vec)
  {
    return std::sqrt(vec.x * vec.x + vec.y * vec.y);
  }

  inline float rot(const sf::Vector2f vec)
  {
    return float(atan2(vec.y, vec.x)) * 180 / 3.14159265F;
  }

  inline float dot(const sf::Vector2f a, const sf::Vector2f b)
  {
    return a.x * b.x + a.y * b.y;
  }

  inline sf::Vector2f rot(const sf::Vector2f vec, float deg)
  {
    float r = 3.14159265F / 180;
    sf::Vector2f out;
    out.x = vec.x * std::cos(r * deg) - vec.y * std::sin(r * deg);
    out.y = vec.x * std::sin(r * deg) + vec.y * std::cos(r * deg);
    return out;
  }

  inline sf::Vector2f fromAngleDeg(float angle)
  {
    float r = M_PI / 180.0;
    return {std::cos(angle * r), std::sin(angle * r)};
  }

  inline sf::Vector2f fromAngleRad(float angle)
  {
    return {std::cos(angle), std::sin(angle)};
  }

  inline float angleRad(sf::Vector2f vec) {
    return atan2f(vec.y,vec.x);
  }

  inline float angleDeg(sf::Vector2f vec) {
    return angleRad(vec) * (180.0 / M_PI);
  }

  inline sf::Vector2f nor(const sf::Vector2f vec)
  {
    float length = len(vec);

    if (length == 0)
    {
      return {0, 0};
    }

    return {vec.x / length, vec.y / length};
  }

  inline sf::Vector2f len(const sf::Vector2f vec, float len)
  {
    auto out = nor(vec);
    return {out.x * len, out.y * len};
  }

  inline sf::Vector2f perpL(const sf::Vector2f vec)
  {
    return {-vec.y, vec.x};
  }

  inline sf::Vector2f perpR(const sf::Vector2f vec)
  {
    return {vec.y, -vec.x};
  }

  inline sf::Vector2f limit(sf::Vector2f vec, float length)
  {
    auto current = len(vec);

    if (current > length)
    {
      vec = nor(vec);
      vec.x *= length;
      vec.y *= length;
    }

    return vec;
  }
}