#include "GameWorld.h"
#include "Game.h"

GameWorld::GameWorld()
    :camera(sf::FloatRect(0, 0, Game::width, Game::height))
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

Terrain *GameWorld::getTerrain()
{
    return terrain;
}

sf::View &GameWorld::getView()
{
    return camera;
}
