#pragma once

#include <Rengine/Core/Types.hxx>
#include <string_view>

namespace Ren::ECS
{

using EntityID = UInt32;

class Entity final
{
public:
    ~Entity() = default;

    EntityID GetEntityID() { return _value << 32; }

private:
    Entity(UInt64 value, std::string_view name);
    UInt64 _value;
};

} // namespace Ren::ECS
