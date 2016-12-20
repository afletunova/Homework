#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

class Entity
{
public:
    Entity();
    virtual ~Entity();

    virtual void load(const std::string filename);
    virtual void setPosition(const float x, const float y);
    virtual sf::Vector2f getEntityPosition() const;
    virtual void update(float elapsedTime);
    virtual void draw(sf::RenderWindow &window);

protected:
    sf::Sprite &getSprite();

private:


    sf::Sprite sprite;
    sf::Texture texture;

    bool loaded;
};