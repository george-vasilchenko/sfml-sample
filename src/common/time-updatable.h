#ifndef TIME_UPDATABLE_H
#define TIME_UPDATABLE_H

class TimeUpdatable
{
public:
    virtual void update(const float &deltaTime) = 0;
    virtual ~TimeUpdatable(){};
};

#endif