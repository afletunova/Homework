#pragma once
#include <QString>

class HashFunction
{
public:
    virtual unsigned int useHashFunction(const QString &word) = 0;
};
