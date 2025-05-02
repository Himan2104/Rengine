#pragma once

#include <Rengine/Core/Definitions.hxx>
#include <format>

namespace Ren
{

struct Version
{
    UInt8 major;
    UInt8 minor;
    UInt8 patch;
};

[[nodiscard]] constexpr bool operator==(const Version& lhs, const Version& rhs) { return (lhs.major == rhs.major) && (lhs.minor == rhs.minor) && (lhs.patch == rhs.patch); }

[[nodiscard]] constexpr bool operator!=(const Version& lhs, const Version& rhs) { return !(lhs == rhs); }

[[nodiscard]] constexpr bool operator<(const Version& lhs, const Version& rhs)
{
    if (lhs.major != rhs.major) return lhs.major < rhs.major;
    if (lhs.minor != rhs.minor) return lhs.minor < rhs.minor;
    return lhs.patch < rhs.patch;
}

[[nodiscard]] constexpr bool operator>(const Version& lhs, const Version& rhs) { return rhs < lhs; }

[[nodiscard]] constexpr bool operator<=(const Version& lhs, const Version& rhs) { return !(rhs < lhs); }

[[nodiscard]] constexpr bool operator>=(const Version& lhs, const Version& rhs) { return !(lhs < rhs); }

} // namespace Ren

template <> struct std::formatter<Ren::Version>
{
    auto format(const Ren::Version& version, std::format_context& ctx) { return std::format_to(ctx.out(), "{}.{}.{}", version.major, version.minor, version.patch); }
};
