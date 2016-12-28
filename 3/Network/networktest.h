#pragma once

#include <QObject>
#include <QtTest/QtTest>

#include "Network/network.h"

using namespace std;

class NetworkTest : public QObject
{
    Q_OBJECT
public:
    explicit NetworkTest(QObject *parent = 0)
        :QObject(parent)
    {}

private:
    vector<Computer *> *computers;
    Network *network;

private slots:
    void init()
    {
        computers = new vector<Computer *>;
    }

    void testThatFirstComputerIsInfectedAfterSimulationStarts()
    {
        computers->push_back(new Computer(2, "PC#1"));
        network = network->createFromList(computers);
        network->startSimulation(1);
        QVERIFY2(network->getComputers()->at(0)->isInfected(), "Computer is not infected");
    }

    void testSecondComputerWithZeroStrengthIsInfected()
    {
        computers->push_back(new Computer(0, "PC#1"));
        computers->push_back(new Computer(0, "PC#2"));
        computers->at(0)->connect(computers->at(1));
        network = network->createFromList(computers);
        network->startSimulation(1);
        QVERIFY2(network->getComputers()->at(1)->isInfected(), "The second computer is not infected");
    }

    void testComputersWithMaximumStrengthFactorAreNotInfected()
    {
        computers->push_back(new Computer(0, "PC#1"));
        computers->push_back(new Computer(101, "PC#2"));
        computers->push_back(new Computer(101, "PC#3"));
        computers->push_back(new Computer(101, "PC#4"));
        computers->at(0)->connect(computers->at(1));
        computers->at(0)->connect(computers->at(2));
        computers->at(0)->connect(computers->at(3));
        network = network->createFromList(computers);
        network->startSimulation(4);
        QVERIFY2(!network->getComputers()->at(1)->isInfected() ||
                 !network->getComputers()->at(2)->isInfected() ||
                 !network->getComputers()->at(3)->isInfected(),
                 "At least two of the computers are infected");
    }

    void cleanup()
    {
        delete computers;
        delete network;
    }
};
