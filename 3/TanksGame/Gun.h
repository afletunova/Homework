#pragma once

#include "Entity.h"

/**
 * @brief The Gun class
 * It implements an Entity object, which is a model for two types of gun object:
 * Remote and Keyboard
 */
class Gun : public Entity
{
public:
    Gun(GameWorld *world);
    virtual void draw(sf::RenderWindow &window);
};
