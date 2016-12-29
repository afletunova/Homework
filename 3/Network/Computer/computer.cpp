#include "computer.h"

Computer::Computer(int strength, const string &name)
    : name(name), strength(strength), infected(false)
{}

void Computer::makeStep(Random *random)
{
    if (!isInfected())
        return;

    int randomStrength = random->generateRandomNumber(1, 101);

    for (Computer *neighbor : neighbors)
        neighbor->infect(randomStrength);
}

bool Computer::infect(int coefficient)
{
    if (infected)
        return infected;
    return infected = coefficient > strength;
}

void Computer::connect(Computer *neighbor)
{
    neighbors.push_back(neighbor);
    neighbor->addNeighbor(this);
}

void Computer::addNeighbor(Computer *neighbor)
{
    neighbors.push_back(neighbor);
}

string Computer::getName() const
{
    return name;
}

bool Computer::isInfected() const
{
    return infected;
}
