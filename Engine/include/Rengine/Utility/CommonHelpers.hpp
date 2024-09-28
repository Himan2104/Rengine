#pragma once
#include<Rengine/Config.hpp>
#include<Rengine/Core/EventSystem.hpp>

namespace ren
{
    namespace CommonHelpers
    {
        EventSystem& REN_API GetEventSystem()
        {
            return EventSystem::GetInstance();
        }
    }
}