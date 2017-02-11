#include <SFML/Graphics/Text.hpp>
#include <cmath>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include "Terrain.h"
#include "Game.h"

void Terrain::draw(sf::RenderWindow &window)
{
    sf::Texture texture;
    sf::Image image;
    image.create(size, Game::height, sf::Color::Transparent);

    for (unsigned int i = 0; i < size; ++i)
    {
        for (unsigned int j = 0; j < vertices[i]; ++j)
        {
            image.setPixel(i, Game::height / 2 - j, sf::Color::Black);
        }
    }

    texture.loadFromImage(image);
    texture.setSmooth(true);
    getSprite()->setTexture(texture);
    window.draw(*getSprite());
}

Terrain::Terrain(GameWorld *world) : Entity(world)
{
    for (int i = 0; i < size; ++i)
        vertices[i] = height;
    generateHeights(0, size);

    auto verticesCopy(vertices);
    for (int i = 40; i < vertices.size() - 40; ++i)
    {
        unsigned int sum = 0;
        for (int j = -40; j < 40; ++j)
            sum += verticesCopy[i + j];
        vertices[i] = sum / 80;
    }
}

void Terrain::generateHeights(int leftBorder, int rightBorder)
{
    int middle = (leftBorder + rightBorder) / 2;
    double coefficient = 1;

    if (std::rand() % 2 == 1)
    {
        int middleHeight = vertices[middle] -= round(vertices[middle] * percent / 100);
        coefficient = (vertices[leftBorder] - middleHeight) * 1000 / (middle - leftBorder);
        coefficient /= 1000;
        for (int i = leftBorder + 1; i < middle; ++i)
            vertices[i] = middleHeight + round(coefficient * (middle - i));
        coefficient = (vertices[rightBorder] - middleHeight) * 1000 / (rightBorder - middle);
        coefficient /= 1000;
        for (int i = middle + 1; i < rightBorder; ++i)
            vertices[i] = middleHeight + round(coefficient * (i - middle));
    } else
    {
        vertices[middle] += round(vertices[middle] * percent / 100);
        int minHeight = vertices[leftBorder];
        coefficient = (vertices[middle] - minHeight) * 1000 / (middle - leftBorder);
        coefficient /= 1000;
        for (int i = leftBorder + 1; i < middle; ++i)
            vertices[i] = (unsigned int) (minHeight + round(coefficient * (i - leftBorder)));
        minHeight = vertices[rightBorder];
        coefficient = (vertices[middle] - minHeight) * 1000 / (rightBorder - middle);
        coefficient /= 1000;
        for (int i = middle + 1; i < rightBorder; ++i)
            vertices[i] = (unsigned int) (minHeight + round(coefficient * (rightBorder - i)));
    }

    if (middle - leftBorder > maxStep)
    {
        generateHeights(leftBorder, middle);
        generateHeights(middle, rightBorder);
    }
    return;
}

float Terrain::getAngle(float x) const
{
    x = round(x);
    int delta = 2;
    int leftX = (int) std::max(0.0f, x - delta / 2);
    int rightX = (int) std::min(x + delta / 2, (float) (size - 1));
    return atan((vertices[rightX] - vertices[leftX]) / delta) * 180 / M_PI;
}

int Terrain::getHeightAt(int x)
{
    return Game::height - vertices[x];
}
