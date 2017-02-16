#pragma once

#include "Entity.h"
#include "KeyboardGun.h"
#include "Tank.h"

/**
 * @brief The KeyboardTank class
 * It implements the tank of the local player
 * It is responsible for updating and sending updates
 */

class KeyboardTank : public Tank
{
public:
    KeyboardTank(GameWorld *world);

    /**
     * @brief update
     * It is responsible for tank motion and updates of the gun
     * Sending commands when motion occurs or have not occurred for a long time
     * @param elapsedTime
     */
    void update(float elapsedTime);

    void draw(sf::RenderWindow &window) override;

private:
    const float speed = 150;
    const float gunHeight = 75;
    static const int updatePackageInterval = 70;

    sf::Clock sendUpdatePackageClock;
    KeyboardGun *gun;
};