#pragma once

#include <SFML/Graphics.hpp>

#include <array>
#include "Entity.h"

class Terrain : public Entity
{
public:
    Terrain(GameWorld *world);

    void draw(sf::RenderWindow &window);
    int getHeightAt(int x);

    const float getAngle(float x);

private:
    const static int size = 4096;
    std::array<unsigned int, size> vertices;

    void generateHeights(int leftBorder, int rightBorder);

    const unsigned int height = 300;
    const int percent = 30;
    const int maxStep = 256;
};

