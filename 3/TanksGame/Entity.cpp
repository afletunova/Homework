#include "Entity.h"

Entity::Entity(GameWorld *world) : world(world), sprite(new sf::Sprite)
{}

void Entity::load(const std::string &filename)
{
    if (!texture.loadFromFile(filename))
        return;

    sprite->setTexture(texture);
}

void Entity::setPosition(float x, float y)
{
    sprite->setPosition(x, y);
}

sf::Sprite *Entity::getSprite() const
{
    return sprite;
}

void Entity::draw(sf::RenderWindow &window)
{
    window.draw(*sprite);
}

float Entity::getPositionX() const
{
    return getSprite()->getPosition().x;
}

float Entity::getPositionY() const
{
    return getSprite()->getPosition().y;
}

GameWorld *Entity::getWorld() const
{
    return world;
}

Entity::~Entity()
{
    delete sprite;
}
