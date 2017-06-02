#include "GameWorld.h"
#include "Game.h"

GameWorld::GameWorld(Game *game) : game(game), isServer(false), shellPrototypes({new Shell(this, 8, 2, 8),
                                                                                 new Shell(this, 6, 8, 20)})
{}

GameWorld::~GameWorld()
{
    delete me;
    delete opponent;
    delete terrain;

    shells.clear();
    explosions.clear();

    for (auto shell : shellPrototypes)
        delete shell;
}

void GameWorld::drawAll(sf::RenderWindow &window)
{
    terrain->draw(window);
    me->draw(window);
    opponent->draw(window);

    for (auto shell : shells)
        if (shell->isActive())
            shell->draw(window);

    for (auto explosion : explosions)
        if (explosion->isActive())
            explosion->draw(window);
}

void GameWorld::addPlayer(KeyboardTank *player)
{
    me = player;
}

void GameWorld::addOpponent(RemoteTank *player)
{
    opponent = player;
}

void GameWorld::updateAll(sf::Time elapsedTime)
{
    me->update(elapsedTime.asSeconds());
    for (auto shell : shells)
        if (shell->isActive())
            shell->update(elapsedTime.asSeconds());

    for (auto explosion : explosions)
        if (explosion->isActive())
            explosion->update(elapsedTime.asSeconds());
}

void GameWorld::addTerrain(Terrain *terrain)
{
    this->terrain = terrain;
}

Terrain *GameWorld::getTerrain()
{
    return terrain;
}

KeyboardTank *GameWorld::getPlayer()
{
    return me;
}

void GameWorld::addShell(Shell *shell)
{
    shells.push_back(shell);
}

NetworkManager *GameWorld::getNetworkManager()
{
    return networkManager;
}

void GameWorld::addNetworkManager(NetworkManager *networkManager)
{
    this->networkManager = networkManager;
}

RemoteTank *GameWorld::getOpponent()
{
    return opponent;
}

void GameWorld::setOnServer(bool isServer)
{
    this->isServer = isServer;
}

bool GameWorld::isOnServer()
{
    return isServer;
}

sf::RenderWindow *GameWorld::getWindow()
{
    return mainWindow;
}

void GameWorld::setWindow(sf::RenderWindow *mainWindow)
{
    this->mainWindow = mainWindow;
}

Game *GameWorld::getGame()
{
    return game;
}

Shell *GameWorld::getShellPrototype(int index)
{
    return shellPrototypes[index];
}

void GameWorld::addExplosion(Explosion *explosion)
{
    explosions.push_back(explosion);
}