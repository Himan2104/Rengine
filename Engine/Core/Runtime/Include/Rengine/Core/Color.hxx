#pragma once

#include <Rengine/Core/Definitions.hxx>
#include <format>

namespace Ren
{

class Color
{
public:
    constexpr Color() = default;

    constexpr Color(UInt8 r, UInt8 g, UInt8 b, UInt8 a);

    constexpr explicit Color(UInt32 color);

    [[nodiscard]] constexpr UInt32 ToUInt32() const { return static_cast<std::uint32_t>((r << 24) | (g << 16) | (b << 8) | a); }

    UInt8 r{}, g{}, b{}, a{255};

    static const Color Zero;
    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Blue;
    static const Color Green;
    static const Color Cyan;
    static const Color Yellow;
    static const Color Magenta;
};

[[nodiscard]] constexpr bool operator==(Color lhs, Color rhs)
{
    return (lhs.r == rhs.r) && (lhs.g == rhs.g) && (lhs.b == rhs.b) && (lhs.a == rhs.a);
}

[[nodiscard]] constexpr bool operator!=(Color lhs, Color rhs) { return !(lhs == rhs); }

} // namespace Ren

template <>
struct std::formatter<Ren::Color>
{
    auto format(const Ren::Color& color, std::format_context& ctx) const
    {
        if (_isHex) return std::format_to(ctx.out(), "#{:x}", color.ToUInt32());
        return std::format_to(ctx.out(), "[{},{},{},{}]", color.r, color.g, color.b, color.a);
    }

    bool _isHex{false};
};
