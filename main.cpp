// g++ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.h"
#include "Player.h"

#pragma once



int main()
{
    //Init Game engine
    Game game;

    Player test;
    game.addPlayer(test);
    

    while (game.running())
    {

        // Update
        game.update();
        game.render();


       /*  sf::Event event;
        while (window.pollEvent(event))
        {

            switch(event.type) {

                case sf::Event::Closed:
                window.close();
                break;

                case sf::Event::TextEntered:
                if(event.text.unicode < 128) printf("%c", event.text.unicode);
                break;

                case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape) window.close();
                
                

                default:
                break;
            }
        } */

      
    
        /* window.clear();
        window.draw(player1);
        window.draw(wall);
        window.display(); */
    }

    return 0;
}