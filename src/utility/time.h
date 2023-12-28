#ifndef TIME_H
#define TIME_H

#include <SFML/Graphics.hpp>
#include "../common/updatable.h"

class Time : public Updatable
{
private:
    sf::Clock *m_clock;
    float m_deltaTime;

public:
    Time();
    ~Time();
    const float &getDeltaTime();

public:
    void update() override;
};

#endif