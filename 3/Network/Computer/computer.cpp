#include "computer.h"

Computer::Computer(int strength, const string &name)
    : name(name), strength(strength), infected(false)
{}

void Computer::makeStep()
{
    if (!isInfected())
        return;

    for (Computer *neighbor : neighbors)
        neighbor->infect(rand() % 100 + 1);
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
