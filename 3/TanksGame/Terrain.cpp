#include <SFML/Graphics/Text.hpp>
#include "Terrain.h"

#include <stdlib.h>
#include <random>


Terrain::Terrain()
{
    for (int i = 0; i < size; ++i)
        vertices[i] = height;
}

Terrain::~Terrain()
{}

void Terrain::draw()
{
    sf::Texture texture;
    sf::Image image;

}

void Terrain::generateHeights(const int step, const int middle)
{
    if (step < minStep)
        return;

    int sign = std::rand() % 2;
    if (sign)
        vertices[middle] += vertices[middle] / 100 * percent;
    else
        vertices[middle] -= vertices[middle] / 100 * percent;



}
