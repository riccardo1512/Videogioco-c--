#include <SFML/Graphics.hpp>

#include "Player.h"

#pragma once

Player::Player() {

    this->shape = new sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
    this->shape->setPosition(100.0f, 100.0f);
}

void Player::movement(sf::RenderWindow* rw) {

    // WINDOW COLLISIONS

    sf::Vector2f pos = this->shape->getPosition();
    sf::Vector2u windowSize = rw->getSize();

    //left border
    if(pos.x <= 0) {

        this->shape->move(-pos.x, 0);

        //right border
    } else if(pos.x + this->shape->getSize().x >= windowSize.x) {

        this->shape->move(- (pos.x + this->shape->getSize().x - windowSize.x), 0);
    }

    //top border
    if(pos.y <= 0) {

        this->shape->move(0, -pos.y);

        //bottom border
    } else if(pos.y + this->shape->getSize().y >= windowSize.y) {

        this->shape->move(0, - (pos.y + this->shape->getSize().y - windowSize.y));
    }


    // KEY MOVEMENT
    
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