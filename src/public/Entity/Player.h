#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

enum State
{
    IDLE,
    RUNNING,
    JUMPING,
    FALLING
};

class Player
{
public:
    Player(float Startx, float Starty, int groundHeight);
    void update();
    void jump();
    void moveLeft();
    void moveRight();
    void handleInput(const sf::Event &event);
    bool isOnGround();

    sf::Sprite getSprite(); // Added 'sf::' namespace qualifier

private:
    sf::Texture texture;
    sf::Sprite sprite;
    float velocityY, velocityX;
    float gravity;
    int groundHeight;
    // movement speed
    float movementSpeed = 8.0f;
    State state;
};

#endif // PLAYER_H
