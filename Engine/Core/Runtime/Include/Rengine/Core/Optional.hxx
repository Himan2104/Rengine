#pragma once

#include <optional>
namespace Ren
{

using NullOpt = std::nullopt_t;

template <typename T> class Optional : std::optional<T>
{
};

} // namespace Ren
