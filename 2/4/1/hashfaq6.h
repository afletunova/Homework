#pragma once

#include "hashfunction.h"

/*!
 * Taken from https://habrahabr.ru/post/219139/
 */

class HashFAQ6 : public HashFunction
{
public:
    unsigned int getHash(const QString &word, const int &hashSize);
};
