#pragma once

#include "Rengine/Core/Definitions.hxx"
#include <format>
#include <map>
#include <string>

namespace Ren::ECS
{

enum class EntityFlags : UInt32
{
    EntityFlagPlaceholder_0  = 1u << 0,
    EntityFlagPlaceholder_1  = 1u << 1,
    EntityFlagPlaceholder_2  = 1u << 2,
    EntityFlagPlaceholder_3  = 1u << 3,
    EntityFlagPlaceholder_4  = 1u << 4,
    EntityFlagPlaceholder_5  = 1u << 5,
    EntityFlagPlaceholder_6  = 1u << 6,
    EntityFlagPlaceholder_7  = 1u << 7,
    EntityFlagPlaceholder_8  = 1u << 8,
    EntityFlagPlaceholder_9  = 1u << 9,
    EntityFlagPlaceholder_10 = 1u << 10,
    EntityFlagPlaceholder_11 = 1u << 11,
    EntityFlagPlaceholder_12 = 1u << 12,
    EntityFlagPlaceholder_13 = 1u << 13,
    EntityFlagPlaceholder_14 = 1u << 14,
    EntityFlagPlaceholder_15 = 1u << 15,
    EntityFlagPlaceholder_16 = 1u << 16,
    EntityFlagPlaceholder_17 = 1u << 17,
    EntityFlagPlaceholder_18 = 1u << 18,
    EntityFlagPlaceholder_19 = 1u << 19,
    EntityFlagPlaceholder_20 = 1u << 20,
    EntityFlagPlaceholder_21 = 1u << 21,
    EntityFlagPlaceholder_22 = 1u << 22,
    EntityFlagPlaceholder_23 = 1u << 23,
    EntityFlagPlaceholder_24 = 1u << 24,
    EntityFlagPlaceholder_25 = 1u << 25,
    EntityFlagPlaceholder_26 = 1u << 26,
    EntityFlagPlaceholder_27 = 1u << 27,
    EntityFlagPlaceholder_28 = 1u << 28,
    EntityFlagPlaceholder_29 = 1u << 29,
    EntityFlagPlaceholder_30 = 1u << 30,
    EntityFlagPlaceholder_31 = 1u << 31
};

class Entity
{
public:
    Entity() = default;

    template <typename T> class IComponent* GetComponent();

private:
    UInt32 _entityID;
    EntityFlags _entityFlags;
};

} // namespace Ren::ECS

template <> struct std::formatter<Ren::ECS::EntityFlags>
{
    auto format(const Ren::ECS::EntityFlags& ef, std::format_context& ctx)
    {
        return std::format_to(ctx.out(), "{}", _enumNameMappings.contains(ef) ? _enumNameMappings.at(ef) : "<EFERROR!>");
    }

private:
    const std::map<Ren::ECS::EntityFlags, std::string> _enumNameMappings = {
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_0, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_1, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_2, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_3, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_4, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_5, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_6, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_7, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_8, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_9, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_10, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_11, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_12, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_13, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_14, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_15, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_16, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_17, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_18, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_19, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_20, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_21, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_22, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_23, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_24, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_25, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_26, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_27, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_28, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_29, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_30, "IsAlive"},
        {Ren::ECS::EntityFlags::EntityFlagPlaceholder_31, "IsAlive"},
    };
};
