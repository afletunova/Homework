#include "Tank.h"
#include "Game.h"

Tank::Tank(GameWorld *world) : Entity(world) {
    load("tank1.png");

    getSprite().setOrigin(getSprite().getGlobalBounds().width / 2, getSprite().getGlobalBounds().height);
    getSprite().setScale(1, 1);
}


void Tank::update(float elapsedTime)
{
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

    getSprite().setPosition(getSprite().getPosition().x, getWorld()->getTerrain()->getHeightAt(getSprite().getPosition().x));
}

