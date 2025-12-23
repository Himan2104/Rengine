#pragma once

#include <Rengine/Core/Config.hxx>
#include <Rengine/Core/Types.hxx>
#include <Rengine/Core/Hash.hxx>
#include <type_traits>

namespace Ren::ECS
{

using ComponentTypeID = UInt64;

// Base class for all components
struct IComponent
{
};

template <typename T>
concept IsComponent = std::is_base_of_v<IComponent, T>;

template <typename T>
consteval ComponentTypeID GetComponentTypeID()
{
    return Hashing::FNV1A(REN_FUNC_SIG);
}

} // namespace Ren::ECS
