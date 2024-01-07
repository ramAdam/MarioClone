#include "Entity/Player.h"
#include <iostream>

Player::Player(float Startx, float Starty, int groundHeight) : velocityY(0), gravity(0.00005f), groundHeight(groundHeight)
{
    texture.loadFromFile("resources/mario.png");
    sprite.setTexture(texture);
    sprite.setPosition(Startx, Starty);
    state = IDLE;
}

void Player::update()
{
    sprite.move(0, velocityY);
    velocityY += gravity;

    if (isOnGround())
    {
        sprite.setPosition(sprite.getPosition().x, groundHeight);
        velocityY = 0;
        sprite.move(velocityX, 0);
    }
    else // in air
    {
        sprite.move(velocityX, 0);
    }
}

void Player::jump()
{
    if (isOnGround())
    {
        velocityY = -0.2f;
        state = JUMPING;
    }
}

void Player::moveLeft()
{

    velocityX = -movementSpeed;
}

void Player::moveRight()
{

    velocityX = movementSpeed;
}

bool Player::isOnGround()
{
    return sprite.getPosition().y >= groundHeight;
}

sf::Sprite Player::getSprite()
{
    return sprite;
}

void Player::handleContinuousInput(std::map<sf::Keyboard::Key, bool> keys)
{
    if (keys[sf::Keyboard::Left])
    {
        moveLeft();
        if (keys[sf::Keyboard::Space]) // If Space is also being pressed
        {
            jump();
        }
    }
    else if (keys[sf::Keyboard::Right])
    {
        moveRight();
        if (keys[sf::Keyboard::Space]) // If Space is also being pressed
        {
            jump();
        }
    }
    else if (keys[sf::Keyboard::Space])
    {
        jump();
    }
    else
    {
        velocityX = 0;
    }
}