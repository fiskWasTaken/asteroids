//
// Created by fisk on 09/12/17.
//

#ifndef ASTEROIDS_VECTOR_H
#define ASTEROIDS_VECTOR_H

#include <SFML/System/Vector2.hpp>

namespace vector {
sf::Vector2f getFromAngle(float angle);
float getLength(sf::Vector2f *vector);
sf::Vector2f *setLength(sf::Vector2f *vector, float length);
sf::Vector2f *normalise(sf::Vector2f *vector);
sf::Vector2f *limit(sf::Vector2f *vector, float length);
}

#endif //ASTEROIDS_VECTOR_H
