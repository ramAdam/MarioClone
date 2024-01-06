#include "Entity/Player.h"

Player::Player(float Startx, float Starty, int groundHeight) : velocityY(0), gravity(0.00005f), groundHeight(groundHeight)
{
    texture.loadFromFile("resources/mario.png");
    sprite.setTexture(texture);
    sprite.setPosition(Startx, Starty);
}

void Player::update()
{
    // Apply gravity
    velocityY += gravity;

    // Move the player
    sprite.move(0, velocityY);

    // Check if the player is on the ground
    if (isOnGround())
    {
        sprite.setPosition(sprite.getPosition().x, groundHeight);
        velocityY = 0;
    }
}

void Player::jump()
{
    if (isOnGround())
    {
        velocityY = -0.2f;
    }
}

void Player::moveLeft()
{
    velocityX = -movementSpeed;
    sprite.move(velocityX, 0);
}

void Player::moveRight()
{
    velocityX = movementSpeed;
    sprite.move(velocityX, 0);
}

bool Player::isOnGround()
{
    return sprite.getPosition().y >= groundHeight;
}

sf::Sprite Player::getSprite()
{
    return sprite;
}

void Player::handleInput(const sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Space:
            jump();
            break;
        case sf::Keyboard::Left:
            moveLeft();
            break;
        case sf::Keyboard::Right:
            moveRight();
            break;
        default:
            break;
        }
    }
}