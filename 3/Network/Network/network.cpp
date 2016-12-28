#include "network.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Network::Network()
{}

Network *Network::createFromList(vector<Computer *> *computers)
{
    Network *network = new Network;
    network->computers.assign(computers->begin(), computers->end());
    return network;
}

Network *Network::createFromFile(const string &filename)
{
    Network *network = new Network;
    ifstream input(filename);

    int OScount = 0;
    input >> OScount;
    for (int i = 0; i < OScount; ++i)
    {
        string OS;
        int count = 0;
        int strength = 0;
        input >> OS >> strength >> count;

        for (int j = 0; j < count; ++j)
        {
            network->computers.push_back(new Computer(strength, OS + "#" + std::to_string(j + 1)));
        }
    }
    int relations = 0;
    input >> relations;

    for (int i = 0; i < relations; ++i)
    {
        int firstComputer = 0;
        int secondComputer = 0;
        input >> firstComputer >> secondComputer;
        network->computers[firstComputer]->connect(network->computers[secondComputer]);
    }
    return network;
}

void Network::startSimulation(int stepCount)
{
    computers[0]->infect(100);

    for (int i = 0; i < stepCount; ++i)
    {
        for (Computer * computer : computers)
            computer->makeStep();
        printStepInfo(i);
    }
}

const vector<Computer *> *Network::getComputers() const
{
    return &computers;
}

Network::~Network()
{
    for (Computer *computer : computers)
        delete computer;
}

void Network::printStepInfo(int step) const
{
    cout << "Step " << step << endl;
    for (Computer *computer : computers)
    {
        cout << "...." << computer->getName() << ".status: ";
        if (computer->isInfected())
            cout << "infected" << endl;
        else
            cout << "is not infected" << endl;
    }

}
