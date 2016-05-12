#include "hashrs.h"

unsigned int HashRs::useHashFunction(const QString &word)
{
    QByteArray byteArray = word.toLocal8Bit();
    char *string = byteArray.data();

    static const unsigned int constant = 378551;
    unsigned int currentValueCoefficient = 63689;
    unsigned int hash = 0;

    for (; *string; ++string)
    {
        hash = hash * currentValueCoefficient + (unsigned char)(*string);
        currentValueCoefficient *= constant;
    }

    return hash;
}
