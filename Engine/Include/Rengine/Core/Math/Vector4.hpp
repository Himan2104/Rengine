#pragma once

#include <Rengine/Core/Definitions.hpp>
#include <cassert>
#include <cmath>

namespace Ren
{
template <typename T> class Vector4
{
public:
    constexpr Vector4() = default;
    constexpr Vector4(T x, T y, T z, T w);

    template <typename U> constexpr explicit operator Vector4<U>() const { return Vector4<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z), static_cast<U>(w)); }

    [[nodiscard]] constexpr T Length() const { return std::sqrt(SquaredLength()); }
    [[nodiscard]] constexpr T SquaredLength() const { return x * x + y * y + z * z + w * w; }
    [[nodiscard]] constexpr Vector4 Normalized() const { return *this / Length(); }

    T x{};
    T y{};
    T z{};
    T w{};
};

// Operator Overloads

template <typename T> [[nodiscard]] constexpr Vector4<T> operator-(Vector4<T> operand) { return Vector4<T>(-operand.x, -operand.y, -operand.z, -operand.w); }

template <typename T> [[nodiscard]] constexpr Vector4<T> operator+(Vector4<T> lhs, Vector4<T> rhs) { return Vector4<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w); }

template <typename T> [[nodiscard]] constexpr Vector4<T> operator-(Vector4<T> lhs, Vector4<T> rhs) { return Vector4<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w); }

template <typename T> [[nodiscard]] constexpr Vector4<T> operator*(Vector4<T> lhs, Vector4<T> rhs) { return Vector4<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w); }

template <typename T> [[nodiscard]] constexpr Vector4<T> operator*(T lhs, Vector4<T> rhs) { return Vector4<T>(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.w * lhs); }

template <typename T> [[nodiscard]] constexpr Vector4<T> operator*(Vector4<T> lhs, T rhs) { return Vector4<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs); }

template <typename T> [[nodiscard]] constexpr Vector4<T> operator/(Vector4<T> lhs, T rhs)
{
    assert((rhs != 0) && "Division By Zero");
    return Vector4<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
}

template <typename T> constexpr Vector4<T>& operator+=(Vector4<T>& lhs, Vector4<T> rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    return lhs;
}

template <typename T> constexpr Vector4<T>& operator-=(Vector4<T>& lhs, Vector4<T> rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;
    return lhs;
}

template <typename T> constexpr Vector4<T>& operator*=(Vector4<T>& lhs, T rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    lhs.w *= rhs;
    return lhs;
}

template <typename T> constexpr Vector4<T>& operator/=(Vector4<T>& lhs, T rhs)
{
    assert((rhs != 0) && "Division by Zero");
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    lhs.w /= rhs;
    return lhs;
}

template <typename T> [[nodiscard]] constexpr bool operator==(Vector4<T> lhs, Vector4<T> rhs) { return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w); }

template <typename T> [[nodiscard]] constexpr bool operator!=(Vector4<T> lhs, Vector4<T> rhs) { return !(lhs == rhs); }

// Helper Functions

template <typename T> [[nodiscard]] constexpr T Dot(const Vector4<T>& lhs, const Vector4<T>& rhs) { return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w); }

// Common Types

using Vector4i8  = Vector4<Int8>;
using Vector4i16 = Vector4<Int16>;
using Vector4i32 = Vector4<Int32>;
using Vector4i64 = Vector4<Int64>;

using Vector4u8  = Vector4<UInt8>;
using Vector4u16 = Vector4<UInt16>;
using Vector4u32 = Vector4<UInt32>;
using Vector4u64 = Vector4<UInt64>;

using Vector4f32 = Vector4<Float32>;
using Vector4f64 = Vector4<Float64>;

} // namespace Ren
