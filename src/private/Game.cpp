#include <SFML/Graphics.hpp>
#include "Animation/Frame.h"
#include "Entity/Player.h"

class Game
{
private:
    sf::RenderWindow window;
    Player player;
    std::map<sf::Keyboard::Key, bool> keys;

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

public:
    Game() : window(sf::VideoMode(1800, 1000), "Mario Game"), player(100.0f, 400.0f, 400) {}

    void handleEvents()
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::KeyPressed)
            {
                keys[event.key.code] = true;

                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                keys[event.key.code] = false;
            }
        }
    }

    void update()
    {
        player.update();
        player.handleContinuousInput(keys);
    }

    void render()
    {
        window.clear();
        window.draw(player.getSprite());
        window.display();
    }

    bool isRunning() const
    {
        return window.isOpen();
    }

    void run()
    {
        while (isRunning())
        {
            handleEvents();
            update();
            render();
        }
    }
};

int main()
{
    Game game;
    game.run();

    return 0;
}
