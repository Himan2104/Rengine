#pragma once
#include <Rengine/Core/Types.hxx>
#include <algorithm>
#include <string_view>

namespace Ren
{

template <UInt32 size>
struct FixedString
{
    constexpr FixedString(const char (&str)[size]) { std::copy_n(str, size, data); }

    constexpr operator std::string_view() const { return std::string_view(data, size - 1); }

    char data[size];
};

} // namespace Ren
