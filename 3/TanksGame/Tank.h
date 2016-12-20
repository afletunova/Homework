#pragma once

#include "Entity.h"

class Tank : public Entity
{
public:
    Tank();
    ~Tank();

    void update(float elapsedTime);

private:
    const float speed = 130;
};