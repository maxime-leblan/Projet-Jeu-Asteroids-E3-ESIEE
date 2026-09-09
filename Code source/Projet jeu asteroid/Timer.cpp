#include "Timer.h"

Timer::Timer()
{
    aCurrentTime = G2D::elapsedTimeFromStartSeconds();
}

double Timer::getCurrentTime()
{
    return aCurrentTime;
}

bool Timer::hasCountInSeconds(double pElapsedTime)
{
    return pElapsedTime <= giveElapsedTime();
}

double Timer::giveElapsedTime() const
{
    return (G2D::elapsedTimeFromStartSeconds() - aCurrentTime);
}

double Timer::giveRemainingTimeBefore(double pTimeToReach) const
{
    return pTimeToReach - giveElapsedTime();
}

void Timer::reset()
{
    aCurrentTime = G2D::elapsedTimeFromStartSeconds();
}