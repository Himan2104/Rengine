#pragma once

#include <Rengine/Core/Types.hxx>

namespace Ren::ECS
{

using EntityID    = UInt32;
using ArchetypeID = UInt32;

class Entity final
{
public:
    Entity()  = default;
    ~Entity() = default;

    EntityID GetEntityID() { return _value << 32; }

private:
    UInt64 _value;
};

} // namespace Ren::ECS
