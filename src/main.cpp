#include <SFML/Graphics.hpp>
#include "utility/time.h"
#include <iostream>
#include <iomanip>
#include "entities/player.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pacman", sf::Style::Default, settings);
    window.setFramerateLimit(60);

    Time t;
    Player p(50, 100);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        t.update();
        p.update(t.getDeltaTime());

        window.draw(p);
        window.display();
    }
}