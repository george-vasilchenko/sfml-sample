#include "player.h"

Player::Player(float radius, float moveSpeed) : sf::CircleShape(radius)
{
    m_moveSpeed = moveSpeed;
    setFillColor(sf::Color(100, 250, 50));
}

void Player::update(const float &deltaTime)
{
    float increment = m_moveSpeed * deltaTime;
    move(increment, 0);
}