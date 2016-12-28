#include <iostream>
#include "Network/network.h"
#include "networktest.h"

using namespace std;

int main()
{
    NetworkTest networkTest;
    QTest::qExec(&networkTest);
    cout << "-----------------------" << endl;

    string filename = "file.txt";
    int steps = 10;
    Network *network = Network::createFromFile(filename);
    network->startSimulation(steps);
    delete network;
    return 0;
}
