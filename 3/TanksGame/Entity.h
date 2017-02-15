#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

class GameWorld;

class Entity
{
public:
    Entity(GameWorld *world);

    virtual ~Entity();

    virtual void load(const std::string &filename);

    virtual void setPosition(float x, float y);

    virtual void draw(sf::RenderWindow &window);

    virtual float getPositionX() const;

    virtual float getPositionY() const;

protected:
    sf::Sprite *getSprite() const;
    GameWorld *getWorld() const;

private:
    sf::Sprite *sprite;
    sf::Texture texture;

    GameWorld *world;
};