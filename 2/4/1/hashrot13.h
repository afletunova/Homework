#pragma once

#include "hashfunction.h"

class HashRot13 : public HashFunction
{
public:
    unsigned int useHashFunction(const QString &word);
};
