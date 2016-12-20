#pragma once
#include <SFML/Graphics.hpp>
#include "GameWorld.h"

class Game
{
public:
    void start();

    const static int width = 1024;
    const static int height = 720;

private:
    void gameLoop();

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);

    sf::RenderWindow mainWindow;
    GameWorld gameWorld;

    enum GameState { Uninitialized, Playing, Paused };

    GameState gameState;
};

