#pragma once

#include "Entity.h"

/**
 * @brief
 * This class is implements shell of guns.
 * It handles collide situation
 */
class Shell : public Entity
{
public:
    Shell(GameWorld *world, float speed, unsigned int radius, float damageRadius);

    ~Shell();

    /**
     * @brief clone
     * @return clone of the current Shell
     */
    Shell *clone() const;

    void update(float elapsedTime);

    void setAngle(float angle);

    bool isActive() const;

    /**
     * @brief collide
     * @param player
     * @return true if shell is collide with the player, false otherwise
     */
    bool isCollide(Entity *player);

    float getSpeed() const;

    unsigned int getRadius() const;

    float getDamageRadius() const;

    void draw(sf::RenderWindow &window) override;

    void setPosition(const float x, const float y) override;

private:
    Shell(const Shell &shell);

    void sendCommand();

    sf::CircleShape shape;

    float speed = 0;
    float angle = 0;
    float time = 0;
    float damageRadius = 0;

    float startX = 0;
    float startY = 0;
    unsigned int radius = 0;

    bool active = true;

    static constexpr float gravity = 9.8f;
};