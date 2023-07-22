#include <SFML/Graphics.hpp>
#include "game_of_life_functions.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML game of life");
    window.setFramerateLimit(10);
    int w = 10;
    //int grid[128][72];
    bool sgrid[128][72];

    sf::Texture t;
    t.loadFromFile("images/life.jpg");
    sf::Sprite s(t);
    fill_array(sgrid,128, 72, 25);

    while (window.isOpen())
    {
        sf::Event event;
        window.clear();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


            for (int i = 0; i < 128; i++)
                for (int j = 0; j < 72; j++)
                {
                    s.setTextureRect(sf::IntRect(sgrid[i][j] * w, 0, w, w));
                    s.setPosition(i * w, j * w);
                    window.draw(s);
                }
            life_step(sgrid, 128, 72);
        window.display();
    }

    return 0;
}