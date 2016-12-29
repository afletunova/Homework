#include "random.h"
#include <cstdlib>

int Random::generateRandomNumber(int from, int to)
{
    return std::rand() % (to - from) + from;
}
