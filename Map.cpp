#include "Map.h"

Map::Map() {

    this->createTwall(50.0f, 50.0f);
}


void Map::createTwall(float xpos, float ypos)
{

    this->vertical.setSize(sf::Vector2f(100.0f, 500.0f));
    this->orizzontal.setSize(sf::Vector2f(500.0f, 100.0f));

    this->vertical.setPosition(xpos, ypos);
    this->orizzontal.setPosition(xpos, (ypos + this->vertical.getSize().y) / 2);


    this->walls.push_back(this->vertical);
    this->walls.push_back(this->orizzontal);
}

std::vector<sf::RectangleShape> Map::returnWalls() {

    return this->walls;
}