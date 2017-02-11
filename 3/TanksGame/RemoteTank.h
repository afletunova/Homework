#pragma once

#include "Entity.h"
#include "KeyboardGun.h"
#include "RemoteGun.h"

class RemoteTank : public Entity
{
public:
    RemoteTank(GameWorld *world);

    void draw(sf::RenderWindow &window) override;

    void setPositionX(int x);

    void setGunRotation(int angle);

    void fire(int angle, int shellIndex);

private:
    RemoteGun *gun;
    const float gunHeight = 75;
};