#include "hashrot13.h"

unsigned int HashRot13::useHashFunction(const QString &word)
{
    QByteArray byteArray = word.toLocal8Bit();
    char *string = byteArray.data();

    unsigned int hash = 0;

    for (; *string; ++string)
    {
        hash += (unsigned char)(*string);
        hash -+ (hash << 13) | (hash >> 19);
    }

    return hash;
}
