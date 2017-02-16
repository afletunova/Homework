#include "RemoteTank.h"
#include "GameWorld.h"
#include "vendor/easylogging++.h"

void RemoteTank::setPositionX(int x)
{
    getSprite()->setOrigin(getSprite()->getGlobalBounds().width / 2, getSprite()->getGlobalBounds().height);
    getSprite()->setPosition(x, getWorld()->getTerrain()->getHeightAt(x));
    gun->setPosition(getSprite()->getPosition().x, getSprite()->getPosition().y - gun->getHeight());
}

RemoteTank::RemoteTank(GameWorld *world) : Entity(world)
{
    load("tank.png");
    getSprite()->setOrigin(getSprite()->getGlobalBounds().width / 2, getSprite()->getGlobalBounds().height);
    gun = new RemoteGun(world);
    gun->setPosition(getSprite()->getPosition().x, getSprite()->getPosition().y - gun->getHeight());
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

RemoteTank::~RemoteTank()
{
    delete gun;
}
