/*************************
Himanshu Parchand - https://himan2104.github.io
A timekeeping library for SFML
Strictly to be used with SFML only
This message may not be removed from any iteration of this code
*************************/
#pragma once
#include<SFML/System.hpp>
#include"Rengine/Config.hpp"

namespace ren
{
    class REN_API TimeKeeper
    {
    public:
        enum class ClockType
        {
            Static  = 0, //Static = clock unaffected by the timescale
            Dynamic = 1 //Dynamic = clock that varies with the timescale
        };

        //use this right before your main game loop
        static void initializeTime();

        //returns the deltaTime in float
        static float deltaTime();

        //change the timescale
        /*
        default = 1.0f
        pause = 0.0f
        */
        static void timeScale(float multiplier);

        //call this at the beginning of your main loop
        static void updateTime();

        //get the time elapsed in seconds
        /*
        Static = clock unaffected by the timescale
        Dynamic = clock that varies with the timescale
        */
        static float timeSinceStart(ClockType _type);

        //returns the current timescale
        static float getTimeScale();

        //returns the frametime
        static float frameTime();

        static void resetClock(ClockType _type);

    private:
        inline static sf::Clock* m_GameClock = nullptr;
        inline static sf::Clock* m_FrameClock = nullptr;
        inline static float m_timeScale = 0.0f;
        inline static float m_deltaTime = 0.0f;
        inline static float m_dynamicClockTime = 0.0f;
    };
}