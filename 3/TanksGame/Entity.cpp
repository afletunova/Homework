#include "Entity.h"

Entity::Entity()
{}

Entity::~Entity()
{}

void Entity::load(const std::string filename)
{
    if (!texture.loadFromFile(filename))
    {
        return;
    }
    sprite.setTexture(texture);
}

void Entity::setPosition(const float x, const float y)
{
    sprite.setPosition(x, y);
}

void Entity::update(float elapsedTime)
{}

sf::Sprite &Entity::getSprite() {
    return sprite;
}

void Entity::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

const float Entity::getPositionX() {
    return getSprite().getPosition().x;
}

const float Entity::getPositionY() {
    return getSprite().getPosition().y;
}
