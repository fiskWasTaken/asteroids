//
// Created by fisk on 24/09/17.
//

#ifndef ASTEROIDS_COLLISION_H
#define ASTEROIDS_COLLISION_H

#include <SFML/System/Vector2.hpp>
#include <vector>

class Collision {
 public:
  bool check(std::vector<sf::Vector2f> a, std::vector<sf::Vector2f> b);
};

#endif //ASTEROIDS_COLLISION_H
