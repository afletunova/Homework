#pragma once

#include "Entity.h"
#include "Tank.h"

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

    bool isCollide(Tank *player);

    float getSpeed() const;

    unsigned int getRadius() const;

    float getDamageRadius() const;

    void draw(sf::RenderWindow &window) override;

    void setPosition(const float x, const float y) override;

private:
    Shell(const Shell &shell);

    sf::CircleShape shape;
    sf::CircleShape bangShape;

    float speed = 0;
    float angle = 0;
    float time = 0;

    float damageRadius = 0;

    float startX = 0;
    float startY = 0;
    unsigned int radius = 0;

    bool active = true;
    bool bang = false;

    static constexpr float gravity = 9.8f;
};