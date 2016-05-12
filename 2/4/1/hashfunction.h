#pragma once

class HashFunction
{
public:
    HashFunction();
    virtual unsigned int useHashFunction(const QString &word);
};
