#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Player.h"

#pragma once

void Game::initVariables() {

    this->window = nullptr;
}

void Game::initWindow() {

    this->videoMode.height = 600;
    this->videoMode.width = 800;
    //this->videoMode.getDesktopMode
    this->window = new sf::RenderWindow(this->videoMode, "Catch It!");
}

void Game::addPlayer(Player p) {

    this->PlayerList.push_back(p);
}

void Game::drawPlayers() {

    Player* ptr;

    for(int i = 0; i < this->PlayerList.size(); i++) {

        ptr = &PlayerList[i];

        this->window->draw(*ptr->shape);
    }
}

Game::Game() {

    this->initVariables();
    this->initWindow();
}

Game::~Game() {


}

// Accessors
const bool Game::running() const {

    return this->window->isOpen();
}

// functions
void Game::pollEvent() {

    while (this->window->pollEvent(this->ev))
        {

            switch(this->ev.type) {

                case sf::Event::Closed:
                this->window->close();
                break;

                case sf::Event::TextEntered:
                if(this->ev.text.unicode < 128) printf("%c", ev.text.unicode);
                break;

                case sf::Event::KeyPressed:
                if(this->ev.key.code == sf::Keyboard::Escape) this->window->close();
                break;
                
                

                default:
                break;
            }
        }


}

void Game::update() {

    this->pollEvent();
}
void Game::render() {

    this->window->clear(sf::Color(255, 0, 0, 255));

    //Draw game objects
    this->drawPlayers();


    this->window->display();
}
