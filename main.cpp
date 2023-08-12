// g++ main.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Catch It!");
    sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
    //player.setFillColor(sf::Color::Red);
    player.setOrigin(50.0f, 50.0f);
    player.setPosition(206.0f, 206.0f);
    
    sf::Texture playerTexture;
    playerTexture.loadFromFile("Tux.png");
    player.setTexture(&playerTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            switch(event.type) {

                case sf::Event::Closed:
                window.close();
                break;

                case sf::Event::Resized:
                std::cout << "New window width: " << event.size.width << ", New window height:  " << event.size.height << std::endl;
                break;

                case sf::Event::TextEntered:
                if(event.text.unicode < 128) printf("%c", event.text.unicode);
                

                // chiude per ogni tasto premuto
                /* case sf::Event::KeyPressed:
                if(event.key.scancode() == sf::Keyboard::Scan::Escape){
                    window.close();
                } */
                

                default:
                break;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player.move(-0.1f, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player.move(0.1f, 0.0f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player.move(0.0, -0.1f);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player.move(0.0f, 0.1f);

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
        }

        

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}