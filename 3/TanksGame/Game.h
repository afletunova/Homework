#pragma once

#include <SFML/Graphics.hpp>
#include "GameWorld.h"
#include "NetworkManager.h"

/**
 * @brief The Game class
 * It contains a logic of a game
 */
class Game
{
public:
    Game(NetworkManager *networkManager, bool isServer);

    ~Game();

    /**
     * @brief start
     * It start the game: add a GameWorld and Entity objects with necessary parameters for the game
     */
    void start();

    /**
     * @brief over
     * It set up "winner" or "loser" status
     * @param localPlayerIsWinner
     */
    void over(bool localPlayerIsWinner);

    bool isOnServer();

    const static int width = 1024;
    const static int height = 720;
    const static int distance = 100;
    const unsigned int fps = 60;

private:
    /**
     * @brief gameLoop
     * It implements game loop: update all object and draw it
     */
    void gameLoop();
    void gameOver();

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

