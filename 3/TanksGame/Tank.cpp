#include "Tank.h"

Tank::Tank(GameWorld *world) : Entity(world)
{}

void Tank::draw(sf::RenderWindow &window)
{
    window.draw(*getSprite());
    gun->draw(window);
}

int Tank::getSpriteRadius() const
{
    return spriteRadius;
}
