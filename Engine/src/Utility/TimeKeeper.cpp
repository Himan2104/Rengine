#include"Rengine/utility/TimeKeeper.hpp"


void ren::TimeKeeper::initializeTime()
{
    m_GameClock = new sf::Clock();
    m_FrameClock = new sf::Clock();

    m_deltaTime = 0.0f;

    m_timeScale = 1.0f;

    m_dynamicClockTime = 0.0f;
    
    m_GameClock->restart().asSeconds();
    m_FrameClock->restart().asSeconds();
}

void ren::TimeKeeper::timeScale(float multiplier)
{
    m_timeScale = multiplier;
}

void ren::TimeKeeper::updateTime()
{
    m_deltaTime = m_FrameClock->getElapsedTime().asSeconds();
    m_FrameClock->restart().asSeconds();
    m_dynamicClockTime += m_deltaTime * m_timeScale;
}

float ren::TimeKeeper::timeSinceStart(ClockType _type)
{
    if (_type == ClockType::Static) return m_GameClock->getElapsedTime().asSeconds();
    else  return m_dynamicClockTime;
}

float ren::TimeKeeper::deltaTime()
{
    return m_deltaTime * m_timeScale;
}

float ren::TimeKeeper::getTimeScale()
{
    return m_timeScale;
}

float ren::TimeKeeper::frameTime()
{
    return m_deltaTime;
}

void ren::TimeKeeper::resetClock(ClockType _type)
{
    if (_type == ClockType::Static) m_GameClock->restart().asSeconds();
    else if (_type == ClockType::Dynamic) m_dynamicClockTime = 0;
}