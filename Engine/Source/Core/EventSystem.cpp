#include "Rengine/Core/EventSystem.hpp"

namespace Ren
{
EventSystem& EventSystem::GetInstance()
{
    static EventSystem instance;
    return instance;
}
} // namespace Ren
