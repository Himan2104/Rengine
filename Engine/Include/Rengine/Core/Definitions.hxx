#pragma once

#include <Rengine/Config.hxx>
#include <cstdint>
#include <stdfloat>

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

// NOTE: The following floating types are not avaialble
// even when using C++23 on my compiler [GCC 14.2.0]
// using Float16  = std::float16_t;
// using Float32  = std::float32_t;
// using Float64  = std::float64_t;
// using Float128 = std::float128_t;

using Float32 = float;
using Float64 = double;

} // namespace Ren
