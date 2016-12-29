#include <iostream>
#include "Network/network.h"
#include "networktest.h"
#include "Random/fakerandom.h"

using namespace std;

int main()
{
    NetworkTest networkTest;
    QTest::qExec(&networkTest);
    cout << "-----------------------" << endl;

    string filename = "file.txt";
    int steps = 10;
    Random *factor = new Random;
    Network *network = Network::createFromFile(filename, factor);
    network->startSimulation(steps);
    delete network;
    return 0;
}
