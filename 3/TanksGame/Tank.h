#pragma once
#include "Entity.h"
#include "Gun.h"

class Tank : public Entity
{
public:
    Tank(GameWorld *world);
    void draw(sf::RenderWindow &window) override;
    int getSpriteRadius() const;

private:
    Gun *gun;
    const int spriteRadius = 75;
};
