#include <SFML/Graphics.hpp>

#include "Player.h"

#pragma once

class Game {

    private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    std::vector<Player> PlayerList;

    void initVariables();
    void initWindow();
    
    

    public:
    Game();
    ~Game();

    // Accessors
    const bool running() const;

    // functions
    void pollEvent();
    void update();
    void render();
    void addPlayer(Player p);
    void drawPlayers();
};