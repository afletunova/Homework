#include "Gun.h"

Gun::Gun(GameWorld *world) : Entity(world)
{}

void Gun::draw(sf::RenderWindow &window)
{
    Entity::draw(window);
}
