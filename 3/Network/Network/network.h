#pragma once

#include <vector>
#include <string>

#include "../Random/random.h"
#include "../Computer/computer.h"

/**
 * @brief The Network class - Network is responsible for networking simulation
 * It simulate a real computer network and shows every  
 */

class Network
{
public:
    /**
     * @brief createFromList - create Network from computers list
     * All computers should be initialized with proper names and neighbors
     * @param computers
     * @param factor
     * @return
     */
    static Network *createFromList(vector<Computer *> *computers, Random *random);
    /**
     * @brief createFromFile - create Network from input file
     * The file should be like:
     * Number of OSs
     * OS, strength, computers count ("number os OSs times)
     * Computers count at all
     * Relations between computers
     * @param filename
     * @param factor
     * @return
     */
    static Network *createFromFile(const string &filename, Random *random);

    /**
     * @brief startSimulation - simulation of the process of infection, depending on the number of steps
     * Infect first computer and trying to infect others
     * @param stepCount
     */
    void startSimulation(int stepCount);
    const vector<Computer *> *getComputers() const;

    ~Network();

private:
    Network();
	
	/**
	 * @brief printStepInfo - for each computer in the Network prints that computer current state
	 * @param step 
	 */
    void printStepInfo(int step) const;

    vector<Computer *> computers;

    Random *random;
};
