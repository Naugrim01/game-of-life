#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML game of life");

    int w = 10;
    //int grid[128][72];
    int sgrid[128][72];

    sf::Texture t;
    t.loadFromFile("images/life.jpg");
    sf::Sprite s(t);
    for (int i =0;i<128;i++)
        for (int j = 0; j < 72; j++)
        {
            sgrid[i][j] = 0;
        }

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
        
        window.display();
    }

    return 0;
}