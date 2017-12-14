#pragma once

#include <SFML/System.hpp>
#include <vector>

namespace shape {
/**
 * Generates a shape.
 * @param points the number of points in the shape
 * @param size the size of the shape
 * @param noise potential difference in point placement (not yet implemented)
 * @return A list of shape vectors.
 */
std::vector<sf::Vector2f> generateShape(unsigned long points, float size, float noise = 0);
};


