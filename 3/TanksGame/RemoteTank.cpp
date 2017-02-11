#include "RemoteTank.h"
#include "GameWorld.h"
#include "Game.h"
#include "vendor/easylogging++.h"

void RemoteTank::setPositionX(int x)
{
    getSprite()->setPosition(x, getWorld()->getTerrain()->getHeightAt(x));
    gun->setPosition(getSprite()->getPosition().x, getSprite()->getPosition().y - gunHeight);
}

RemoteTank::RemoteTank(GameWorld *world) : Entity(world)
{
    load("tank1.png");
    getSprite()->setOrigin(getSprite()->getGlobalBounds().width / 2, getSprite()->getGlobalBounds().height);
    gun = new RemoteGun(world);
    gun->setPosition(getSprite()->getPosition().x, getSprite()->getPosition().y - gunHeight);
}

void RemoteTank::draw(sf::RenderWindow &window)
{
    Entity::draw(window);
    gun->draw(window);
}

void RemoteTank::setGunRotation(int angle)
{
    gun->setRotation(angle);
}

void RemoteTank::fire(int angle, int shellIndex)
{
    gun->fire(angle, shellIndex);
}
