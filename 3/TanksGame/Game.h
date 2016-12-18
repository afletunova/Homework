#pragma once
#include <SFML/Graphics.hpp>
#include "Tank.h"

class Game
{
public:
    static void Start();

private:
    static void gameLoop();
    static void update();

    static void updatePlayer();

    static sf::RenderWindow mainWindow;
    static Tank player;

    enum GameState { Uninitialized, ShowingSplash, Paused,
        ShowingMenu, Playing, Exiting };

    static GameState gameState;
};

