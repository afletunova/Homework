#pragma once

#include "Entity.h"
#include "Shell.h"

class KeyboardGun : public Entity
{
public:
    KeyboardGun(GameWorld *world);

    ~KeyboardGun();

    void update(float x, float y);

private:
    const float startAngle = 270;
    const float angle = 5;
    const float maxAngle = 360;
    const float minAngle = 180;
    const int reloadTimeMS = 700;


    void fire();

    sf::Vector2f getFirePosition() const;

    sf::Clock clock;
    int shellIndex = 0;

    void changeShell();
};
