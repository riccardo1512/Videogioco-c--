#include <SFML/Graphics.hpp>

#pragma once

class Player {

    public:
        int speed;

        sf::RectangleShape* shape;

        Player();
};