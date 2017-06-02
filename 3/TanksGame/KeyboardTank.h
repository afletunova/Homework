#pragma once

#include "Entity.h"
#include "KeyboardGun.h"

/**
 * @brief The KeyboardTank class
 * It implements the tank of the local player
 * It is responsible for updating and sending updates
 */

class KeyboardTank : public Entity
{
public:
    KeyboardTank(GameWorld *world);

    ~KeyboardTank();

    /**
     * @brief update
     * It is responsible for tank motion and updates of the gun
     * Sending commands when motion occurs or have not occurred for a long time
     * @param elapsedTime
     */
    void update(float elapsedTime);

    void draw(sf::RenderWindow &window) override;

    static const int spriteRadius = 45;

private:
    const float speed = 150;
    static const int updatePackageInterval = 70;

    sf::Clock sendUpdatePackageClock;
    KeyboardGun *gun;
};