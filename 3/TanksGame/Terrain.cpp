#include <SFML/Graphics/Text.hpp>
#include "Terrain.h"

Terrain::Terrain()
{
    for (int i = 0; i < size; ++i)
        vertices[i] = height;
}

Terrain::~Terrain()
{}

void Terrain::draw(sf::RenderWindow &window)
{
    sf::Texture texture;
    sf::Image image;
    image.create(size, 2 * height);

    generateHeights();

    for (unsigned int i = 0; i < size; ++i)
    {
        for (unsigned int j = 0; j < vertices[i]; ++j)
            image.setPixel(i, j, sf::Color::Transparent);
        for (unsigned int j = vertices[i]; j < 2 * height; ++j)
            image.setPixel(i, j, sf::Color::Black);
    }

    texture.loadFromImage(image);

    getSprite().setTexture(texture);

    window.draw(getSprite());

}

void Terrain::generateHeights()
{
    for (int i = 2; i < size / 16; ++i)
    {
        if (i % 4 == 0)
            vertices[i] = vertices[i - 1] - 1;
        else
            vertices[i] = vertices[i - 1];
    }

    for (int i = size / 16; i < size / 8; ++i)
        if (i % 3 == 0)
            vertices[i] = vertices[i - 1] + 1;
        else
            vertices[i] = vertices[i - 1];

    for (int i = size / 8; i < size / 8 + size / 16; ++i)
        vertices[i] = vertices[i - 1];


    for (int i = size / 8 + size / 16; i < size / 4; ++i)
        if (i % 2 == 0)
            vertices[i] = vertices[i - 1];
        else
            vertices[i] = vertices[i - 1] - 1;

    for (int i = size / 4; i < size / 4 + size / 16; ++i)
        if (i % 6 == 0)
            vertices[i] = vertices[i - 1] - 1;
        else
            vertices[i] = vertices[i - 1];

    for (int i = size / 4 + size / 16; i < size / 4 + size / 8 + size / 16; ++i)
        if (i % 4 == 0)
            vertices[i] = vertices[i - 1] + 1;
        else
            vertices[i] = vertices[i - 1];

    for (int i = size / 4 + size / 8 + size / 16; i < size / 2; ++i)
        if (i % 3 == 0)
            vertices[i] = vertices[i - 1] - 1;
        else
            vertices[i] = vertices[i - 1];

    for (int i = size / 2; i < size / 2 + size / 8; ++i)
        if (i % 4 == 0)
            vertices[i] = vertices[i - 1] - 1;
        else
            vertices[i] = vertices[i - 1];

    for (int i = size / 2 + size / 8; i < size / 2 + size / 4; ++i)
        if (i % 7 == 0)
            vertices[i] = vertices[i - 1] + 1;
        else
            vertices[i] = vertices[i - 1];

    for (int i = size / 2 + size / 4; i < size / 2 + size / 4 + size / 16; ++i)
        if (i % 8 == 0)
            vertices[i] = vertices[i - 1] + 2;
        else
            vertices[i] = vertices[i - 1];

    for (int i = size / 2 + size / 4 + size / 16; i < size / 2 + size / 4 + size / 8; ++i)
        if (i % 4 == 0)
            vertices[i] = vertices[i - 1] - 1;
        else
            vertices[i] = vertices[i - 1];

    for (int i = size / 2 + size / 4 + size / 8; i < size / 2 + size / 4 + size / 8 + size / 16; ++i)
        if (i % 5 == 0)
            vertices[i] = vertices[i - 1] + 2;
    else
            vertices[i] = vertices[i - 1];

    for (int i = size / 2 + size / 4 + size / 8 + size / 16; i < size; ++i)
        vertices[i] = vertices[i - 1];
}