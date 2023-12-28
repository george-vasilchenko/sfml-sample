#include "time.h"

Time::Time()
{
    m_clock = new sf::Clock();
    m_deltaTime = 0;
}

Time::~Time()
{
    delete m_clock;
}

const float &Time::getDeltaTime()
{
    return m_deltaTime;
}

void Time::update()
{
    m_deltaTime = m_clock->restart().asSeconds();
}