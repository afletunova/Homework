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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) &&
            getWorld()->getWindow()->hasFocus() &&
            clock.getElapsedTime().asMilliseconds() >= reloadTimeMS)
    {
        LOG(INFO) << "Fire!";
        fire();
        clock.restart();
    }

    if (direction != 0)
    {
        Command command;
        command.name = "rotate";
        command.argumentsCount = 1;
        command.arguments = new int[command.argumentsCount];
        command.arguments[0] = (int) getSprite()->getRotation();
        getWorld()->getNetworkManager()->send(command);
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
    LOG(INFO) << "Shell is added; KeyboardGun::fire";
    getWorld()->addShell(shell);

    Command command;
    command.name = "fire";
    command.argumentsCount = 2;
    command.arguments = new int[command.argumentsCount];
    command.arguments[0] = (int) getSprite()->getRotation();
    command.arguments[1] = shellIndex;

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
