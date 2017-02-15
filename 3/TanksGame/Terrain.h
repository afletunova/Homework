#pragma once

#include <SFML/Graphics.hpp>

#include <array>
#include "Entity.h"

class Terrain : public Entity
{
public:
    Terrain(GameWorld *world, int seed);

    void draw(sf::RenderWindow &window);

    int getHeightAt(int x);

    float getAngle(float x) const;

private:
    const static int size = 1024;
    std::array<unsigned int, size> vertices;

    void generateHeights(int leftBorder, int rightBorder);

    const unsigned int height = 300;
    unsigned int seed = 1;
    const int percent = 30;
    const int maxStep = 64;
};

