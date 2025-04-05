#pragma once

#include "SFML/System/Vector3.hpp"
#include <Rengine/Core/Definitions.hpp>
#include <cassert>
#include <cmath>

namespace Ren
{
template <typename T> class Vector3
{
public:
    constexpr Vector3() = default;
    constexpr Vector3(T x, T y, T z)
        : x{x}
        , y{y}
        , z{z}
    {
    }

    template <typename U> constexpr explicit operator Vector3<U>() const { return Vector3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z)); }

    constexpr operator sf::Vector3<T>() const { return sf::Vector3<T>(x, y, z); }

    [[nodiscard]] constexpr T Length() const { return std::sqrt(SquaredLength()); };
    [[nodiscard]] constexpr T SquaredLength() const { return x * x + y * y + z * z; }
    [[nodiscard]] constexpr Vector3 Normalized() const { *this / Length(); }

    T x{};
    T y{};
    T z{};
};

// Operator Overloads

template <typename T> [[nodiscard]] constexpr Vector3<T> operator-(Vector3<T> operand) { return Vector3<T>(-operand.x, -operand.y, -operand.z); }

template <typename T> [[nodiscard]] constexpr Vector3<T> operator+(Vector3<T> lhs, Vector3<T> rhs) { return Vector3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z); }

template <typename T> [[nodiscard]] constexpr Vector3<T> operator-(Vector3<T> lhs, Vector3<T> rhs) { return Vector3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z); }

template <typename T> [[nodiscard]] constexpr Vector3<T> operator*(Vector3<T> lhs, Vector3<T> rhs) { return Vector3<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z); }

template <typename T> [[nodiscard]] constexpr Vector3<T> operator*(T lhs, Vector3<T> rhs) { return Vector3<T>(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs); }

template <typename T> [[nodiscard]] constexpr Vector3<T> operator*(Vector3<T> lhs, T rhs) { return Vector3<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs); }

template <typename T> [[nodiscard]] constexpr Vector3<T> operator/(Vector3<T> lhs, T rhs)
{
    assert((rhs != 0) && "Division By Zero");
    return Vector3<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

template <typename T> constexpr Vector3<T>& operator+=(Vector3<T>& lhs, Vector3<T> rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return lhs;
}

template <typename T> constexpr Vector3<T>& operator-=(Vector3<T>& lhs, Vector3<T> rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return lhs;
}

template <typename T> constexpr Vector3<T>& operator*=(Vector3<T>& lhs, T rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    return lhs;
}

template <typename T> constexpr Vector3<T>& operator/=(Vector3<T>& lhs, T rhs)
{
    assert((rhs != 0) && "Division by Zero");
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    return lhs;
}

template <typename T> [[nodiscard]] constexpr bool operator==(Vector3<T> lhs, Vector3<T> rhs) { return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z); }

template <typename T> [[nodiscard]] constexpr bool operator!=(Vector3<T> lhs, Vector3<T> rhs) { return !(lhs == rhs); }

// Helper Functions

template <typename T> [[nodiscard]] constexpr T Dot(const Vector3<T>& lhs, const Vector3<T>& rhs) { return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z); }

template <typename T> [[nodiscard]] constexpr Vector3<T> Cross(const Vector3<T>& lhs, const Vector3<T>& rhs) { return Vector3<T>((lhs.y * rhs.z) - (lhs.z * rhs.y), (lhs.z * rhs.x) - (lhs.x * rhs.z), (lhs.x * rhs.y) - (lhs.y * rhs.x)); }

// Common Types

using Vector3i8  = Vector3<Int8>;
using Vector3i16 = Vector3<Int16>;
using Vector3i32 = Vector3<Int32>;
using Vector3i64 = Vector3<Int64>;

using Vector3u8  = Vector3<UInt8>;
using Vector3u16 = Vector3<UInt16>;
using Vector3u32 = Vector3<UInt32>;
using Vector3u64 = Vector3<UInt64>;

using Vector3f32 = Vector3<Float32>;
using Vector3f64 = Vector3<Float64>;

} // namespace Ren
