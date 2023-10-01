#include <SFML/Graphics.hpp>

#pragma once

class Map {

    public:
    sf::RectangleShape vertical;
    sf::RectangleShape orizzontal;
    
    std::vector<sf::RectangleShape> walls;

    Map();

    void createTwall(float xpos, float ypos);

    std::vector<sf::RectangleShape> returnWalls();
};