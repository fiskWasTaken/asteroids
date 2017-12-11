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
float len(sf::Vector2f vector);
float rot(sf::Vector2f vector);
float dot(sf::Vector2f a, sf::Vector2f b);

sf::Vector2f fromAngle(float angle);

sf::Vector2f rot(sf::Vector2f vector, float degrees);

sf::Vector2f len(sf::Vector2f vector, float length);
sf::Vector2f normalise(sf::Vector2f vector);
sf::Vector2f limit(sf::Vector2f vector, float length);
sf::Vector2f perpL(sf::Vector2f vector);
sf::Vector2f perpR(sf::Vector2f vector);
}

#endif //ASTEROIDS_VECTOR_H
