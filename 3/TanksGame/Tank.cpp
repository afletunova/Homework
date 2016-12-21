#include "Tank.h"
#include "Game.h"

Tank::Tank()
{
    load("tank.png");

    getSprite().setOrigin(getSprite().getScale().x / 2, 0);
}

Tank::~Tank() {}

void Tank::update(float elapsedTime) {

    int direction = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        direction = -1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        direction = +1;

    float x = speed * elapsedTime;
    if (getSprite().getPosition().x < 0
        || getSprite().getPosition().x > Game::width)
    {
        direction = 0;
        getSprite().move(-getSprite().getPosition().x, 0);
    }

    getSprite().move(direction * x, 0);
    std::cout << getSprite().getPosition().x << std::endl;
}

