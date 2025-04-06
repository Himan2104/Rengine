#pragma once

#include "Rengine/Core/Definitions.hpp"

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
