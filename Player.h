#include <SFML/Graphics.hpp>

#pragma once

class Player {

    public:
        int speed = 5.0f;

        sf::RectangleShape* shape;

        Player();
        void movement();
};