#pragma once

#include <SFML/Graphics.hpp>

#include <array>
#include "Entity.h"

/**
 * @brief The Terrain class
 * Generates a random heights array and made a random terrain
 */
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

    const unsigned int height = 250;
    unsigned int seed = 1;
    const int percent = 20;
    const int maxStep = 64;
};

