#pragma once

#include <string>
#include <vector>
#include "../Random/random.h"

using namespace std;

/**
 * @brief The Computer class - computer that belongs to Network
 * Can be infect by other neighbor, and can infect others.
 */
class Computer
{
public:
    Computer(int strength, const string &name);

    string getName() const;
    bool isInfected() const;

    /**
     * @brief makeStep - passes through neighbors and tries to infect them
     * @param random
     */
    void makeStep(Random *random);
    /**
     * @brief infect - attempts to infect computer with given probability
     * @param coefficient - random number
     * @return
     */
    bool infect(int coefficient);
    /**
     * @brief connect - connects current computer with other
     * @param neighbor
     */
    void connect(Computer *neighbor);

private:
    void addNeighbor(Computer *neighbor);

    string name;
    int strength;
    bool infected;
    vector<Computer *> neighbors;
};

