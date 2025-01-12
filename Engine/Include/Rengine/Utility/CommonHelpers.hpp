#pragma once
#include<Rengine/Config.hpp>
#include<Rengine/Core/EventSystem.hpp>

namespace Ren
{
    namespace CommonHelpers
    {
        EventSystem& GetEventSystem()
        {
            return EventSystem::GetInstance();
        }
    }
}