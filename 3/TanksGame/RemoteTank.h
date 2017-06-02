#pragma once

#include "KeyboardGun.h"
#include "RemoteGun.h"

/**
 * @brief The RemoteTank class
 * Implements the logic of an opponent's tank
 */
class RemoteTank : public Entity
{
public:
    RemoteTank(GameWorld *world);

    ~RemoteTank();

    void draw(sf::RenderWindow &window) override;

    void setPositionX(int x);

    void setGunRotation(int angle);

    void fire(int angle, int shellIndex);

private:
    RemoteGun *gun;
};