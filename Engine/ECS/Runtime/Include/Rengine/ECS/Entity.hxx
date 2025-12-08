#pragma once

#include <Rengine/Core/Definitions.hxx>
#include <Rengine/ECS/EntityFlags.hxx>

namespace Ren::ECS
{

class Entity
{
public:
    Entity() = default;

    template <typename T>
    class IComponent* GetComponent();

private:
    UInt32 _entityID;
    EntityFlags _entityFlags;
};

} // namespace Ren::ECS
