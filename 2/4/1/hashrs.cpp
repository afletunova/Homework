#include "hashrs.h"

unsigned int HashRs::useHashFunction(const QString &word)
{
    static const unsigned int constant = 378551;
    unsigned int currentValueCoefficient = 63689;
    unsigned int hash = 0;

    for (; *word; ++word)
    {
        hash = hash * currentValueCoefficient + (unsigned char)(*word);
        currentValueCoefficient *= constant;
    }

    return hash;
}
