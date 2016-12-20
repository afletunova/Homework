#pragma once

#include <iostream>

#include "Entity.h"
#include "Tank.h"

class GameWorld {
public:
    GameWorld();
    ~GameWorld();

    //void add(const std::string name, Entity *entity);
    void addPlayer(Tank *player);
    //void remove(const std::string name);

    //unsigned long getEntityCount() const;

    //Entity *get(const std::string name) const;

    void updateAll(sf::Time);
    void drawAll(sf::RenderWindow &window);

private:
    Tank *player;

    //std::map<std::string, Entity *> entities;

    //struct EntitiesDeallocator
    //{
    //    void operator()(const std::pair<std::string, Entity *> &pair) const
    //    {
    //        delete pair.second;
    //    }
    //};
};