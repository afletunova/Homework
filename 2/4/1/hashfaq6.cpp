#include "hashfaq6.h"

unsigned int HashFAQ6::getHash(const QString &word, const int &hashSize)
{
    QByteArray byteArray = word.toLocal8Bit();
    char *string = byteArray.data();
    unsigned int hash = 0;

    for (; *string; ++string)
    {
        hash += (unsigned char)(*string);
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash % hashSize;
}
