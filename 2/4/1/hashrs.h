#pragma once

#include "hashfunction.h"

class HashRs : public HashFunction
{
public:
    unsigned int useHashFunction(const QString &word);
};
