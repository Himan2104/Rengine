#pragma once

#include <Rengine/Core/Config.hxx>
#include <cstddef>
#include <cstdint>
#include <stdfloat>
#include <string_view>

namespace Ren
{

using Bool = bool;

using Char = char;

using Byte = char;

using Int8  = std::int8_t;
using Int16 = std::int16_t;
using Int32 = std::int32_t;
using Int64 = std::int64_t;

using UInt8  = std::uint8_t;
using UInt16 = std::uint16_t;
using UInt32 = std::uint32_t;
using UInt64 = std::uint64_t;

#ifdef REN_ENABLE_STD_FLOAT
using Float16  = std::float16_t;
using Float32  = std::float32_t;
using Float64  = std::float64_t;
using Float128 = std::float128_t;
#else
using Float32 = float;
using Float64 = double;
#endif

template <typename T>
constexpr std::string_view NameOf()
{
#if defined(__clang__) || defined(__GNUC__)
    std::string_view name   = REN_FUNC_SIG;
    std::string_view prefix = "[with T = ";
    std::string_view suffix = ";";
#elif defined(_MSC_VER)
    std::string_view name   = REN_FUNC_SIG;
    std::string_view prefix = "NameOf<";
    std::string_view suffix = ">(void)";
#endif

    size_t start = name.find(prefix) + prefix.size();
    size_t end   = name.find(suffix, start);
    return name.substr(start, end - start);
}

template <typename T>
constexpr UInt64 TypeID()
{
    // FNV1A based hashing
    auto name          = NameOf<T>();
    UInt64 hash        = 0xcbf29ce484222325;
    const UInt64 prime = 0x100000001b3;

    for (char c : name)
    {
        hash ^= static_cast<UInt64>(c);
        hash *= prime;
    }
    return hash;
}

} // namespace Ren
