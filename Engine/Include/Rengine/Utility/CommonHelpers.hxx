#pragma once
#include<Rengine/Config.hxx>
#include<Rengine/Core/EventSystem.hxx>

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