#pragma once

#include <iostream>
#include <vector>

#include "Entity.h"
#include "KeyboardTank.h"
#include "Terrain.h"
#include "NetworkManager.h"
#include "RemoteTank.h"

class Game;

class GameWorld
{
public:
    GameWorld(Game *game);

    ~GameWorld();

    void addPlayer(KeyboardTank *player);

    void addOpponent(RemoteTank *player);

    void addTerrain(Terrain *terrain);

    void addNetworkManager(NetworkManager *networkManager);

    void setCamera(float y);

    void setWindow(sf::RenderWindow *mainWindow);

    void updateAll(sf::Time);

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

    sf::View &getView();

private:
    std::vector<Shell *> shells;
    const std::vector<Shell *> shellPrototypes;
    KeyboardTank *me;
    RemoteTank *opponent;
    Terrain *terrain;
    NetworkManager *networkManager;
    sf::View camera;

    Game *game;

    sf::RenderWindow *mainWindow;

    bool isServer;
};