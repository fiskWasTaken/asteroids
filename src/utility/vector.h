//
// Created by fisk on 09/12/17.
//

#ifndef ASTEROIDS_VECTOR_H
#define ASTEROIDS_VECTOR_H

#include <SFML/System/Vector2.hpp>

/**
 * All setter functions take a reference and return the reference for chaining
 */
namespace vector {
sf::Vector2f fromAngle(float angle);
float len(sf::Vector2f *vector);
sf::Vector2f *len(sf::Vector2f *vector, float length);
sf::Vector2f *normalise(sf::Vector2f *vector);
sf::Vector2f *limit(sf::Vector2f *vector, float length);
}

#endif //ASTEROIDS_VECTOR_H
