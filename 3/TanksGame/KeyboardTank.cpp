#include "vendor/easylogging++.h"
#include "KeyboardTank.h"
#include "Game.h"

KeyboardTank::KeyboardTank(GameWorld *world) : Entity(world)
{
    load("tank.png");

    getSprite()->setOrigin(getSprite()->getGlobalBounds().width / 2, getSprite()->getGlobalBounds().height);
    gun = new KeyboardGun(world);
}


void KeyboardTank::update(float elapsedTime)
{
    int direction = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && getWorld()->getWindow()->hasFocus())
        direction = -1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && getWorld()->getWindow()->hasFocus())
        direction = +1;

    float x = speed * elapsedTime;
    if (getSprite()->getPosition().x < 0)
    {
        direction = 0;
        getSprite()->setPosition(0, getSprite()->getPosition().y);
    }
    if (getSprite()->getPosition().x > Game::width)
    {
        direction = 0;
        getSprite()->move(Game::width - getSprite()->getPosition().x, 0);
    }

    getSprite()->move(direction * x, 0);
    getSprite()->setPosition(getSprite()->getPosition().x,
                             getWorld()->getTerrain()->getHeightAt((int) getSprite()->getPosition().x));
    gun->update(getSprite()->getPosition().x, getSprite()->getPosition().y - gun->getHeight());

    if (direction != 0 || sendUpdatePackageClock.getElapsedTime().asMilliseconds() >= updatePackageInterval)
    {
        Command command("move", 1);
        command.addArgument((int) getSprite()->getPosition().x, 0);
        if (sendUpdatePackageClock.getElapsedTime().asMilliseconds() >= updatePackageInterval)
        {
            getWorld()->getNetworkManager()->send(command);
            sendUpdatePackageClock.restart();
        }
    }
}

void KeyboardTank::draw(sf::RenderWindow &window)
{
    window.draw(*getSprite());
    gun->draw(window);
}

KeyboardTank::~KeyboardTank()
{
    delete gun;
}
