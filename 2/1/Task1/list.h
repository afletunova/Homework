#pragma once

class List
{
public:
    virtual bool addElementToList(int value) = 0;
    virtual bool removeElementFromList(int value) = 0;
    virtual int getSize() = 0;
    virtual ~List(){}
};
