#include "GameWorld.h"
#include "Game.h"

GameWorld::GameWorld()
{}

GameWorld::~GameWorld()
{
    delete player;
    delete terrain;
}

void GameWorld::drawAll(sf::RenderWindow &window)
{
    player->draw(window);
    terrain->draw(window);
}

void GameWorld::addPlayer(Tank *player)
{
    GameWorld::player = player;
}

void GameWorld::updateAll(sf::Time ups)
{
    player->update(ups.asSeconds());
}

void GameWorld::addTerrain(Terrain *terrain)
{
     GameWorld::terrain = terrain;
}

void GameWorld::setCamera(const float &y)
{
    camera.setCenter(player->getPositionX(), y / 2);
}
