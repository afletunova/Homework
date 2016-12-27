#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

class GameWorld;

class Entity
{
public:
    Entity(GameWorld *world);
    virtual ~Entity(){}

    GameWorld *getWorld();

    virtual void load(const std::string filename);
    virtual void setPosition(const float x, const float y);
    virtual void update(float elapsedTime);
    virtual void draw(sf::RenderWindow &window);

    virtual const float getPositionX();
    virtual const float getPositionY();

protected:
    sf::Sprite &getSprite();

private:

    sf::Sprite sprite;
    sf::Texture texture;

    GameWorld *world;
};