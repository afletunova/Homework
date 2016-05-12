#pragma once

#include "hashfunction.h"

class HashFAQ6 : public HashFunction
{
public:
    unsigned int useHashFunction(const QString &word);
};
