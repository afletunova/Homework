#include "Entity.h"

Entity::Entity()
{}

Entity::~Entity()
{}

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    states.texture = &texture;
    target.draw(sprite);
}

void Entity::load(const std::string filename)
{
    texture.loadFromFile(filename);
    sprite.setTexture(texture);
}

void Entity::setPosition(const int x, const int y)
{
    sprite.setPosition(x, y);
}
