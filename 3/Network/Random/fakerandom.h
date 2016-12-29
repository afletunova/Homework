#pragma once

#include "random.h"

/**
 * @brief
 * Always return max possible values
 */

class FakeRandom : public Random
{
public:
    int generateRandomNumber(int from, int to);
};
