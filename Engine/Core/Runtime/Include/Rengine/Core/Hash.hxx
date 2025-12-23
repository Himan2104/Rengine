#pragma once

#include <Rengine/Core/Types.hxx>
#include <string_view>

namespace Ren
{
namespace Hashing
{

    constexpr UInt64 FNV1A(std::string_view str)
    {
        UInt64 hash            = 0xCBF29CE484222325;
        constexpr UInt64 prime = 0x100000001B3;

        for (Char c : str)
        {
            hash ^= static_cast<UInt64>(c);
            hash *= prime;
        }

        return hash;
    }

} // namespace Hashing
} // namespace Ren
