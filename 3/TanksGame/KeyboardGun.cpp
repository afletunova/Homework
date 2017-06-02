#include <math.h>
#include "KeyboardGun.h"
#include "GameWorld.h"
#include "vendor/easylogging++.h"

KeyboardGun::KeyboardGun(GameWorld *world) : Entity(world)
{
    load("gun.png");

    getSprite()->setOrigin(0, getSprite()->getGlobalBounds().height / 2);
    getSprite()->setRotation(startAngle);
}

void KeyboardGun::update(float x, float y)
{
    int direction = 0;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && getWorld()->getWindow()->hasFocus())
        direction = -1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && getWorld()->getWindow()->hasFocus())
        direction = 1;

    if (getSprite()->getRotation() < minAngle && getSprite()->getRotation() > minAngle / 2)
    {
        direction = 0;
        getSprite()->rotate(minAngle - getSprite()->getRotation());
    }
    if (getSprite()->getRotation() < angle + 1)
    {
        direction = 0;
        getSprite()->rotate(maxAngle - getSprite()->getRotation() - angle);
    }

    getSprite()->rotate(direction * angle);

    setPosition(x, y);

    changeShell();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) &&
        getWorld()->getWindow()->hasFocus() &&
        clock.getElapsedTime().asMilliseconds() >= reloadTimeMS)
    {
        fire();
        clock.restart();
    }

    if (direction != 0 || sendUpdatePackageClock.getElapsedTime().asMilliseconds() >= updatePackageInterval * 2)
    {
        Command command("rotate", 1);
        command.addArgument((int) getSprite()->getRotation(), 0);
        if (sendUpdatePackageClock.getElapsedTime().asMilliseconds() >= updatePackageInterval)
        {
            getWorld()->getNetworkManager()->send(command);
            sendUpdatePackageClock.restart();
        }
    }
}

KeyboardGun::~KeyboardGun()
{}

void KeyboardGun::fire()
{
    Shell *shell = getWorld()->getShellPrototype(shellIndex)->clone();
    shell->setAngle(getSprite()->getRotation());
    sf::Vector2f position = getFirePosition();
    shell->setPosition(position.x, position.y);
    getWorld()->addShell(shell);

    Command command("fire", 2);
    command.addArgument((int) getSprite()->getRotation(), 0);
    command.addArgument(shellIndex, 1);

    getWorld()->getNetworkManager()->send(command);
}

sf::Vector2f KeyboardGun::getFirePosition() const
{
    sf::Vector2f position(getPositionX(), getPositionY());
    float rotationRadians = getSprite()->getRotation() * M_PI / 180;
    position += getSprite()->getLocalBounds().width * sf::Vector2f(cos(rotationRadians), sin(rotationRadians));

    return position;
}

void KeyboardGun::changeShell()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
        shellIndex = 0;
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
        shellIndex = 1;
}

float KeyboardGun::getHeight()
{
    return height;
}
