#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "../common/time-updatable.h"

class Player : public sf::CircleShape, public TimeUpdatable
{
private:
    float m_moveSpeed;

public:
    Player(float radius, float moveSpeed);
    void update(const float &deltaTime);
};

#endif