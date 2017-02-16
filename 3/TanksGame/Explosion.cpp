#include "Explosion.h"

Explosion::Explosion(GameWorld *world, float radius, float x, float y) : Entity(world)
{
    shape.setFillColor(sf::Color::White);
    shape.setRadius(radius * 8);
    shape.setOrigin(radius * 4, radius * 4);
    shape.setPosition(x, y);
}

bool Explosion::isActive()
{
    return active;
}

void Explosion::draw(sf::RenderWindow &window)
{
    window.draw(shape, getSprite()->getTransform());
}

void Explosion::update(float elapsedTime)
{
    time = time + elapsedTime;
    if (time > 0.5)
        active = false;
}
