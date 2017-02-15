#pragma once

#include "Entity.h"

class Gun : Entity
{
public:
    Gun(GameWorld *world);
    virtual void draw(sf::RenderWindow &window);
};
