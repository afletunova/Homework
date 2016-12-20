#include "GameWorld.h"
#include "Game.h"

GameWorld::GameWorld()
{}

GameWorld::~GameWorld()
{
    delete player;
    //std::for_each(entities.begin(), entities.end(), EntitiesDeallocator());
}

//void GameWorld::add(const std::string name, Entity *entity)
//{
//    std::pair<std::string, Entity *> pair = std::make_pair(name, entity);
//    entities.insert(pair);
//}

//void GameWorld::remove(const std::string name)
//{
//    std::map<std::string, Entity *>::iterator results = entities.find(name);
//    if (results != entities.end())
//    {
//        delete results->second;
//        entities.erase(results);
//    }
//}

//unsigned long GameWorld::getEntityCount() const
//{
//    return entities.size();
//}

//Entity *GameWorld::get(const std::string name) const
//{
//std::map<std::string, Entity *>::const_iterator results = entities.find(name);
//    if (results == entities.end())
//        return nullptr;
//    return results->second;
//}

void GameWorld::drawAll(sf::RenderWindow &window)
{
    //std::map<std::string, Entity *>::const_iterator iterator = entities.begin();
    //while (iterator != entities.end())
    //{
    //window.draw(*iterator->second);
    //    ++iterator;
    //}
    player->draw(window);
}

void GameWorld::addPlayer(Tank *player)
{
    GameWorld::player = player;
}

void GameWorld::updateAll(sf::Time ups)
{
    player->update(ups.asSeconds());
}
