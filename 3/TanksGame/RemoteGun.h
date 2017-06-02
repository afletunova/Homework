#pragma once

#include "Entity.h"
#include "Shell.h"

/**
 * @brief The RemoteGun class
 * Implements logic of an opponent's tank's gun
 */
class RemoteGun : public Entity
{
public:
    RemoteGun(GameWorld *world);

    void setRotation(int angle);

    /**
     * @brief fire
     * Add shell ang set position and angle to it
     * @param angle
     * @param shellIndex
     */
    void fire(int angle, int shellIndex);

    float getHeight();

private:
    const float startAngle = 270;
    const float height = 75;

    sf::Vector2f getFirePosition() const;
};
