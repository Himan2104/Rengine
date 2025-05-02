#include "Rengine/Core/EventSystem.hxx"

namespace Ren
{
EventSystem& EventSystem::GetInstance()
{
    static EventSystem instance;
    return instance;
}
} // namespace Ren
