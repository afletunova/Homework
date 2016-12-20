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

sf::Vector2f Entity::getEntityPosition() const
{
    return sf::Vector2f();
}

sf::Sprite &Entity::getSprite() {
    return sprite;
}

void Entity::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}
