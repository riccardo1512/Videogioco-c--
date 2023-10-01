#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Map.h"

#pragma once

class Game {

    private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    std::vector<Player> PlayerList;

    Map* map;

    void initVariables();
    void initWindow();
    void initMap();
    
    

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
    void updatePlayers();

    void drawMap();
};