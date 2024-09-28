#include "Rengine/Core/EventSystem.hpp"

namespace ren
{
    EventSystem &EventSystem::GetInstance()
    {
        static EventSystem instance;
        return instance;
    }

    void IEvent::Invoke(const IEvent &event)
    {

    }
}