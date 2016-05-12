#pragma once
#include <QString>

class HashFunction
{
public:
    HashFunction();
    virtual unsigned int useHashFunction(const QString &word);
};
