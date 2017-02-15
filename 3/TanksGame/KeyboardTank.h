#pragma once

#include "Entity.h"
#include "KeyboardGun.h"
#include "Tank.h"

class KeyboardTank : public Tank
{
public:
    KeyboardTank(GameWorld *world);

    void update(float elapsedTime);

    void draw(sf::RenderWindow &window) override;

private:
    const float speed = 200;
    const float gunHeight = 75;
    static const int updatePackageInterval = 40;

    sf::Clock sendUpdatePackageClock;
    KeyboardGun *gun;
};