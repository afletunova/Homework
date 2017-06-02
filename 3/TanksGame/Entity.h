#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

class GameWorld;

/**
 * @brief The Entity class
 * This abstract model for objects that appear in the GameWorld
 */
class Entity
{
public:
    Entity(GameWorld *world);

    virtual ~Entity();

    /**
     * @brief load
     * It load picture from file and sets it to the sprite as a parameter
     * @param filename
     */
    virtual void load(const std::string &filename);

    /**
     * @brief setPosition
     * It sets position to the Entity object by set position to the sprite
     * @param x
     * @param y
     */
    virtual void setPosition(float x, float y);

    /**
     * @brief draw
     * It draws the Entity object by draw sprite on the window
     * @param window
     */
    virtual void draw(sf::RenderWindow &window);

    /**
     * @brief getPositionX
     * It returns an x position of the sprite
     */
    virtual float getPositionX() const;

    /**
     * @brief getPositionY
     * It returns an y position of the sprite
     */
    virtual float getPositionY() const;

protected:
    sf::Sprite *getSprite() const;

    GameWorld *getWorld() const;

private:
    sf::Sprite *sprite;
    sf::Texture texture;

    GameWorld *world;
};