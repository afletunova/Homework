#pragma once

#include <SFML/Graphics.hpp>

class BackgroundGenerator
{
public:
    sf::VertexArray getBackground();

private:
    //sf::VertexArray lines(sf::LinesStrip, backgroundSize);
    static const int backgroundSize = 1024;
};