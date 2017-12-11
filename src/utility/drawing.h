#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace drawing {
void drawHealthBar(
    sf::RenderWindow *renderWindow,
    int health,
    int maxHealth,
    sf::Vector2f pos,
    sf::Vector2f origin
);
}