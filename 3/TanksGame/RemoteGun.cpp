#include <math.h>

#include "vendor/easylogging++.h"
#include "RemoteGun.h"
#include "Shell.h"
#include "GameWorld.h"

void RemoteGun::setRotation(int angle)
{
    getSprite()->setRotation(angle);
}

RemoteGun::RemoteGun(GameWorld *world) : Entity(world)
{
    load("gun.png");
    getSprite()->setRotation(startAngle);
}

void RemoteGun::fire(int angle, int shellIndex)
{
    Shell *shell = getWorld()->getShellPrototype(shellIndex)->clone();
    shell->setAngle(getSprite()->getRotation());
    sf::Vector2f position = getFirePosition();
    shell->setPosition(position.x, position.y);
    LOG(INFO) << "Shell is added; RemoteGun::fire";
    getWorld()->addShell(shell);
}

sf::Vector2f RemoteGun::getFirePosition() const
{
    sf::Vector2f position(getPositionX(), getPositionY());
    float rotationRadians = getSprite()->getRotation() * M_PI / 180;
    position += getSprite()->getLocalBounds().width * sf::Vector2f(cos(rotationRadians), sin(rotationRadians));

    return position;
}
