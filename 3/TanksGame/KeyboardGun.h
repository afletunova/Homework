#pragma once

#include "Entity.h"
#include "Shell.h"

/**
 * @brief The KeyboardGun class
 * It implements the gun of the local player and
 * it is responsible for updating and sending update information of gun rotation and fire
 */
class KeyboardGun : public Entity
{
public:
    KeyboardGun(GameWorld *world);

    ~KeyboardGun();

    /**
     * @brief update
     * It is responsible for motion and actions of the tanks gun
     * @param x
     * @param y
     */
    void update(float x, float y);

    float getHeight();

private:
    const float startAngle = 270;
    const float angle = 5;
    const float maxAngle = 360;
    const float minAngle = 180;
    const float height = 75;
    const int reloadTimeMS = 600;
    const int updatePackageInterval = 150;

    void fire();

    sf::Vector2f getFirePosition() const;

    sf::Clock clock;
    sf::Clock sendUpdatePackageClock;
    int shellIndex = 0;

    void changeShell();
};
