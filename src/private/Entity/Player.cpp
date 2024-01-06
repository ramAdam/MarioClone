#include "Entity/Player.h"

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
        state = IDLE;
    }
    else
    {
        sprite.move(velocityX, 0);
    }
}

void Player::jump()
{
    if (isOnGround())
    {
        velocityY = -0.2f;
        // sprite.move(0, velocityY);
        state = JUMPING;
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
    else if (event.type == sf::Event::KeyReleased)
    {
        switch (event.key.code)
        {
        case sf::Keyboard::Left:
        case sf::Keyboard::Right:
            velocityX = 0;
            break;
        default:
            break;
        }
    }
}