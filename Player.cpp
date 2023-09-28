#include <SFML/Graphics.hpp>

#include "Player.h"

#pragma once

Player::Player() {

    this->shape = new sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
}