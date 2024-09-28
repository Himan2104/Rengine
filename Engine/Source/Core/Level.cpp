#include <Rengine/core/Level.hpp>

void ren::Level::InternalTick(float deltaTime)
{
    Update(deltaTime);
}
