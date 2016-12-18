#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

class Entity : public sf::Drawable, public sf::Transformable
{
public:
    Entity();
    virtual ~Entity();

    virtual void load(const std::string filename);
    virtual void setPosition(const int x, const int y);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::Vector2f position;

    sf::Sprite sprite;
    sf::Texture texture;
};