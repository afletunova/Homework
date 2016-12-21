#pragma once

#include <iostream>

#include "Entity.h"
#include "Tank.h"
#include "Terrain.h"

class GameWorld {
public:
    GameWorld();
    ~GameWorld();

    void addPlayer(Tank *player);
    void addTerrain(Terrain *terrain);
    void setCamera(const float &y);

    void updateAll(sf::Time);
    void drawAll(sf::RenderWindow &window);

private:
    Tank *player;
    Terrain *terrain;
    sf::View camera;
};