// g++ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Catch It!");

    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    //player.setFillColor(sf::Color::Red);
    player.setOrigin(50.0f, 50.0f);
    player.setPosition(500.0f, 500.0f);
    

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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player.move(-3.0f, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player.move(3.0f, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.move(0.0, -3.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.move(0.0f, 3.0f);

        

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}