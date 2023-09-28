// g++ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <iostream>



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Catch It!");

    sf::RectangleShape player1(sf::Vector2f(100.0f, 100.0f));
    player1.setPosition(500.0f, 500.0f);

    sf::RectangleShape wall(sf::Vector2f(100.0f, 100.0f));
    wall.setOrigin(50.0f, 50.0f);
    wall.setPosition(200.0f, 200.0f);
    

    while (window.isOpen())
    {
        sf::Event event;
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
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player1.move(-3.0f, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player1.move(3.0f, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player1.move(0.0, -3.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player1.move(0.0f, 3.0f);

        

        window.clear();
        window.draw(player1);
        window.draw(wall);
        window.display();
    }

    return 0;
}