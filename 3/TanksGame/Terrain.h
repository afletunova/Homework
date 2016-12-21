#pragma once

#include <SFML/Graphics.hpp>

#include <array>
#include "Entity.h"

class Terrain : public Entity
{
public:
    Terrain();
    ~Terrain();

    void draw(sf::RenderWindow &window);
private:
    const static int size = 4096;
    std::array<unsigned int, size> vertices;

    void generateHeights();

    const unsigned int height = 300;
};

