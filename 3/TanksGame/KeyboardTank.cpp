#include "vendor/easylogging++.h"
#include "KeyboardTank.h"
#include "Game.h"

KeyboardTank::KeyboardTank(GameWorld *world) : Tank(world)
{
    load("tank1.png");

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
    gun->update(getSprite()->getPosition().x, getSprite()->getPosition().y - gunHeight);

    if (direction != 0 || sendUpdatePackageClock.getElapsedTime().asMilliseconds() >= updatePackageInterval)
    {
        Command command;
        command.name = "move";
        command.argumentsCount = 1;
        command.arguments = new int[1];
        command.arguments[0] = (int) getSprite()->getPosition().x;
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
