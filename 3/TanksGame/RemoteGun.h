#pragma once

#include "Entity.h"
#include "Shell.h"

class RemoteGun : public Gun
{
public:
    RemoteGun(GameWorld *world);

    void setRotation(int angle);

    void fire(int angle, int shellIndex);

private:
    const float startAngle = 270;
    sf::Vector2f getFirePosition() const;
};
