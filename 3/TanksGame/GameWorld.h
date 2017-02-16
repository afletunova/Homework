#pragma once

#include <iostream>
#include <vector>

#include "Entity.h"
#include "KeyboardTank.h"
#include "Terrain.h"
#include "NetworkManager.h"
#include "RemoteTank.h"

class Game;

/**
 * @brief The GameWorld class
 * This class is implements a game world and it is responsible for updating and drawing all the objects
 */
class GameWorld
{
public:
    GameWorld(Game *game);

    ~GameWorld();

    void addPlayer(KeyboardTank *player);

    void addOpponent(RemoteTank *player);

    void addTerrain(Terrain *terrain);

    void addNetworkManager(NetworkManager *networkManager);

    void setWindow(sf::RenderWindow *mainWindow);

    /**
     *@brief updateAll
     * It calls an update function for player and shells
     */
    void updateAll(sf::Time);

    /**
     * @brief drawAll
     * It draws all the objects which contains in the game world
     * @param window
     */

    void drawAll(sf::RenderWindow &window);

    void addShell(Shell *shell);

    void setOnServer(bool isServer);

    sf::RenderWindow *getWindow();

    bool isOnServer();

    Terrain *getTerrain();

    NetworkManager *getNetworkManager();

    KeyboardTank *getPlayer();

    RemoteTank *getOpponent();

    Game *getGame();

    Shell *getShellPrototype(int index);

private:
    std::vector<Shell *> shells;
    const std::vector<Shell *> shellPrototypes;
    KeyboardTank *me;
    RemoteTank *opponent;
    Terrain *terrain;
    NetworkManager *networkManager;

    Game *game;

    sf::RenderWindow *mainWindow;

    bool isServer;
};