#include"Rengine/utility/TimeKeeper.hpp"


void Ren::TimeKeeper::InitializeTime()
{
    m_GameClock = new sf::Clock();
    m_FrameClock = new sf::Clock();

    m_deltaTime = 0.0f;

    m_timeScale = 1.0f;

    m_dynamicClockTime = 0.0f;
    
    m_GameClock->restart().asSeconds();
    m_FrameClock->restart().asSeconds();
}

void Ren::TimeKeeper::SetTimeScale(float multiplier)
{
    m_timeScale = multiplier;
}

void Ren::TimeKeeper::UpdateTime()
{
    m_deltaTime = m_FrameClock->getElapsedTime().asSeconds();
    m_FrameClock->restart().asSeconds();
    m_dynamicClockTime += m_deltaTime * m_timeScale;
}

float Ren::TimeKeeper::TimeSinceStart(ClockType _type)
{
    if (_type == ClockType::Static) return m_GameClock->getElapsedTime().asSeconds();
    else  return m_dynamicClockTime;
}

float Ren::TimeKeeper::DeltaTime()
{
    return m_deltaTime * m_timeScale;
}

float Ren::TimeKeeper::GetTimeScale()
{
    return m_timeScale;
}

float Ren::TimeKeeper::GetFrameTime()
{
    return m_deltaTime;
}

void Ren::TimeKeeper::ResetClock(ClockType _type)
{
    if (_type == ClockType::Static) m_GameClock->restart().asSeconds();
    else if (_type == ClockType::Dynamic) m_dynamicClockTime = 0;
}