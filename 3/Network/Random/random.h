#pragma once

/**
 * @brief The Random class
 * Generates random number as it should
 */
class Random
{
public:
    /**
     * @brief generateRandomNumber
     * Generates random number in range
     * @param from start range inclusive
     * @param to end range exclusive
     * @return
     */
    virtual int generateRandomNumber(int from, int to);
};
