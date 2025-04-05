#pragma once

#include "SFML/System/Vector2.hpp"
#include <Rengine/Core/Definitions.hpp>
#include <Rengine/Core/ISerializable.hpp>
#include <cassert>
#include <cmath>
#include <format>

namespace Ren
{
template <typename T> class Vector2
{
public:
    constexpr Vector2() = default;
    constexpr Vector2(T x, T y)
        : x{x}
        , y{y}
    {
    }

    template <typename U> constexpr explicit operator Vector2<U>() const { return Vector2<U>(static_cast<U>(x), static_cast<U>(y)); }

    constexpr operator sf::Vector2<T>() const { return sf::Vector2<T>(x, y); }

    [[nodiscard]] constexpr T Length() const { return std::sqrt(SquaredLength()); }
    [[nodiscard]] constexpr T SquaredLength() const { return (x * x) + (y * y); }
    [[nodiscard]] constexpr Vector2 Normalized() const { return *this / Length(); }
    [[nodiscard]] constexpr Vector2 Perpendicular() const { return Vector2<T>(-y, x); }

    T x{};
    T y{};
};

// Operator Overloads

template <typename T> [[nodiscard]] constexpr Vector2<T> operator-(Vector2<T> operand) { return Vector2<T>(-operand.x, -operand.y); }

template <typename T> [[nodiscard]] constexpr Vector2<T> operator+(Vector2<T> lhs, Vector2<T> rhs) { return Vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y); }

template <typename T> [[nodiscard]] constexpr Vector2<T> operator-(Vector2<T> lhs, Vector2<T> rhs) { return Vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y); }

template <typename T> [[nodiscard]] constexpr Vector2<T> operator*(Vector2<T> lhs, Vector2<T> rhs) { return Vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y); }

template <typename T> [[nodiscard]] constexpr Vector2<T> operator*(T lhs, Vector2<T> rhs) { return Vector2<T>(rhs.x * lhs, rhs.y * lhs); }

template <typename T> [[nodiscard]] constexpr Vector2<T> operator*(Vector2<T> lhs, T rhs) { return Vector2<T>(lhs.x * rhs, lhs.y * rhs); }

template <typename T> [[nodiscard]] constexpr Vector2<T> operator/(Vector2<T> lhs, T rhs)
{
    assert((rhs != 0) && "Division By Zero");
    return Vector2<T>(lhs.x / rhs, lhs.y / rhs);
}

template <typename T> constexpr Vector2<T>& operator+=(Vector2<T>& lhs, Vector2<T> rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

template <typename T> constexpr Vector2<T>& operator-=(Vector2<T>& lhs, Vector2<T> rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

template <typename T> constexpr Vector2<T>& operator*=(Vector2<T>& lhs, T rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;
}

template <typename T> constexpr Vector2<T>& operator/=(Vector2<T>& lhs, T rhs)
{
    assert((rhs != 0) && "Division by Zero");
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}

template <typename T> [[nodiscard]] constexpr bool operator==(Vector2<T> lhs, Vector2<T> rhs) { return (lhs.x == rhs.x) && (lhs.y == rhs.y); }

template <typename T> [[nodiscard]] constexpr bool operator!=(Vector2<T> lhs, Vector2<T> rhs) { return !(lhs == rhs); }

// Helper Functions

template <typename T> [[nodiscard]] constexpr T Dot(const Vector2<T>& lhs, const Vector2<T>& rhs) { return (lhs.x * rhs.x) + (lhs.y * rhs.y); }

template <typename T> [[nodiscard]] constexpr T Cross(const Vector2<T>& lhs, const Vector2<T>& rhs) { return (lhs.x * rhs.y) - (lhs.y * rhs.x); }

// Common Types

using Vector2i8  = Vector2<Int8>;
using Vector2i16 = Vector2<Int16>;
using Vector2i32 = Vector2<Int32>;
using Vector2i64 = Vector2<Int64>;

using Vector2u8  = Vector2<UInt8>;
using Vector2u16 = Vector2<UInt16>;
using Vector2u32 = Vector2<UInt32>;
using Vector2u64 = Vector2<UInt64>;

using Vector2f32 = Vector2<Float32>;
using Vector2f64 = Vector2<Float64>;

} // namespace Ren

template <typename T> struct std::formatter<Ren::Vector2<T>> : std::formatter<T>
{
    auto format(const Ren::Vector2<T>& vec, std::format_context& ctx) { return std::format_to(ctx.out(), "[{}, {}]", vec.x, vec.y); }
};
