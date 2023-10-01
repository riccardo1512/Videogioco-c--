#include <SFML/Graphics.hpp>

#include "Player.h"

#pragma once

Player::Player() {

    this->shape = new sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
    this->shape->setPosition(100.0f, 100.0f);
}

void Player::movement() {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {

        this->shape->move(-this->speed, 0);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

        this->shape->move(this->speed, 0);
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

        this->shape->move(0, -this->speed);
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

        this->shape->move(0, this->speed);
    }
}