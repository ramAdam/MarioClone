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
    void handleContinuousInput(std::map<sf::Keyboard::Key, bool> keys);
    bool isOnGround();

    sf::Sprite getSprite(); // Added 'sf::' namespace qualifier

private:
    sf::Texture texture;
    sf::Sprite sprite;
    float velocityY, velocityX;
    float gravity;
    int groundHeight;
    // movement speed
    float movementSpeed = 0.1f;
    State state;
};

#endif // PLAYER_H
