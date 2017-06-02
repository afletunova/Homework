#pragma once

#include "Entity.h"

/**
 * @brief The Explosion class
 * Implements explosion of the shells then it collide with terrain or player
 */
class Explosion : public Entity
{
public:
    Explosion(GameWorld *world, float radius, float x, float y);

    bool isActive();

    void draw(sf::RenderWindow &window) override;

    /**
     * @brief
     * Update lifetime of the explosion
     * @param elapsedTime
     */
    void update(float elapsedTime);

private:
    bool active = true;

    float time = 0;

    sf::CircleShape shape;
};
