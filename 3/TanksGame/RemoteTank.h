#pragma once

#include "KeyboardGun.h"
#include "RemoteGun.h"
#include "Tank.h"

class RemoteTank : public Tank
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