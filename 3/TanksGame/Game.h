#pragma once

#include <SFML/Graphics.hpp>
#include "GameWorld.h"
#include "NetworkManager.h"

class Game
{
public:
    Game(NetworkManager *networkManager, bool isServer);

    ~Game();

    bool start();
    void over(bool localPlayerIsWinner);

    bool isOnServer();

    const static int width = 1024;
    const static int height = 720;
    const static int distance = 100;
    const unsigned int fps = 60;

private:
    void gameLoop();

    sf::Clock clock;
    sf::Time accumulator = sf::Time::Zero;
    sf::Time ups = sf::seconds(1.f / 60.f);

    sf::RenderWindow mainWindow;

    GameWorld *world;

    enum GameState
    {
        Playing, Ended
    };

    GameState gameState;

    NetworkManager *networkManager;

    bool isServer;
    bool localPlayerIsWinner;
};

