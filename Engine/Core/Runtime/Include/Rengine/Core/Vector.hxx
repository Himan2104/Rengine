#pragma once

#include <Rengine/Core/Types.hxx>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <cassert>
#include <cmath>
#include <format>

namespace Ren
{

template <typename T>
class Vector2
{
public:
    constexpr Vector2() = default;
    constexpr Vector2(T x, T y)
        : x{x}
        , y{y}
    {
    }

    template <typename U>
    constexpr explicit operator Vector2<U>() const
    {
        return Vector2<U>(static_cast<U>(x), static_cast<U>(y));
    }

    constexpr operator sf::Vector2<T>() const { return sf::Vector2<T>(x, y); }

    [[nodiscard]] constexpr T Length() const { return std::sqrt(SquaredLength()); }
    [[nodiscard]] constexpr T SquaredLength() const { return (x * x) + (y * y); }
    [[nodiscard]] constexpr Vector2 Normalized() const { return *this / Length(); }
    [[nodiscard]] constexpr Vector2 Perpendicular() const { return Vector2<T>(-y, x); }

    T x{};
    T y{};
};

// Operator Overloads

template <typename T>
[[nodiscard]] constexpr Vector2<T> operator-(Vector2<T> operand)
{
    return Vector2<T>(-operand.x, -operand.y);
}

template <typename T>
[[nodiscard]] constexpr Vector2<T> operator+(Vector2<T> lhs, Vector2<T> rhs)
{
    return Vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template <typename T>
[[nodiscard]] constexpr Vector2<T> operator-(Vector2<T> lhs, Vector2<T> rhs)
{
    return Vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template <typename T>
[[nodiscard]] constexpr Vector2<T> operator*(Vector2<T> lhs, Vector2<T> rhs)
{
    return Vector2<T>(lhs.x * rhs.x, lhs.y * rhs.y);
}

template <typename T>
[[nodiscard]] constexpr Vector2<T> operator*(T lhs, Vector2<T> rhs)
{
    return Vector2<T>(rhs.x * lhs, rhs.y * lhs);
}

template <typename T>
[[nodiscard]] constexpr Vector2<T> operator*(Vector2<T> lhs, T rhs)
{
    return Vector2<T>(lhs.x * rhs, lhs.y * rhs);
}

template <typename T>
[[nodiscard]] constexpr Vector2<T> operator/(Vector2<T> lhs, T rhs)
{
    assert((rhs != 0) && "Division By Zero");
    return Vector2<T>(lhs.x / rhs, lhs.y / rhs);
}

template <typename T>
constexpr Vector2<T>& operator+=(Vector2<T>& lhs, Vector2<T> rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

template <typename T>
constexpr Vector2<T>& operator-=(Vector2<T>& lhs, Vector2<T> rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

template <typename T>
constexpr Vector2<T>& operator*=(Vector2<T>& lhs, T rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;
}

template <typename T>
constexpr Vector2<T>& operator/=(Vector2<T>& lhs, T rhs)
{
    assert((rhs != 0) && "Division by Zero");
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}

template <typename T>
[[nodiscard]] constexpr bool operator==(Vector2<T> lhs, Vector2<T> rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y);
}

template <typename T>
[[nodiscard]] constexpr bool operator!=(Vector2<T> lhs, Vector2<T> rhs)
{
    return !(lhs == rhs);
}

// Helper Functions

template <typename T>
[[nodiscard]] constexpr T Dot(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y);
}

template <typename T>
[[nodiscard]] constexpr T Cross(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return (lhs.x * rhs.y) - (lhs.y * rhs.x);
}

template <typename T>
class Vector3
{
public:
    constexpr Vector3() = default;
    constexpr Vector3(T x, T y, T z)
        : x{x}
        , y{y}
        , z{z}
    {
    }

    template <typename U>
    constexpr explicit operator Vector3<U>() const
    {
        return Vector3<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z));
    }

    constexpr operator sf::Vector3<T>() const { return sf::Vector3<T>(x, y, z); }

    [[nodiscard]] constexpr T Length() const { return std::sqrt(SquaredLength()); };
    [[nodiscard]] constexpr T SquaredLength() const { return x * x + y * y + z * z; }
    [[nodiscard]] constexpr Vector3 Normalized() const { *this / Length(); }

    T x{};
    T y{};
    T z{};
};

// Operator Overloads

template <typename T>
[[nodiscard]] constexpr Vector3<T> operator-(Vector3<T> operand)
{
    return Vector3<T>(-operand.x, -operand.y, -operand.z);
}

template <typename T>
[[nodiscard]] constexpr Vector3<T> operator+(Vector3<T> lhs, Vector3<T> rhs)
{
    return Vector3<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

template <typename T>
[[nodiscard]] constexpr Vector3<T> operator-(Vector3<T> lhs, Vector3<T> rhs)
{
    return Vector3<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

template <typename T>
[[nodiscard]] constexpr Vector3<T> operator*(Vector3<T> lhs, Vector3<T> rhs)
{
    return Vector3<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z);
}

template <typename T>
[[nodiscard]] constexpr Vector3<T> operator*(T lhs, Vector3<T> rhs)
{
    return Vector3<T>(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}

template <typename T>
[[nodiscard]] constexpr Vector3<T> operator*(Vector3<T> lhs, T rhs)
{
    return Vector3<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

template <typename T>
[[nodiscard]] constexpr Vector3<T> operator/(Vector3<T> lhs, T rhs)
{
    assert((rhs != 0) && "Division By Zero");
    return Vector3<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}

template <typename T>
constexpr Vector3<T>& operator+=(Vector3<T>& lhs, Vector3<T> rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    return lhs;
}

template <typename T>
constexpr Vector3<T>& operator-=(Vector3<T>& lhs, Vector3<T> rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    return lhs;
}

template <typename T>
constexpr Vector3<T>& operator*=(Vector3<T>& lhs, T rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    return lhs;
}

template <typename T>
constexpr Vector3<T>& operator/=(Vector3<T>& lhs, T rhs)
{
    assert((rhs != 0) && "Division by Zero");
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    return lhs;
}

template <typename T>
[[nodiscard]] constexpr bool operator==(Vector3<T> lhs, Vector3<T> rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
}

template <typename T>
[[nodiscard]] constexpr bool operator!=(Vector3<T> lhs, Vector3<T> rhs)
{
    return !(lhs == rhs);
}

// Helper Functions

template <typename T>
[[nodiscard]] constexpr T Dot(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z);
}

template <typename T>
[[nodiscard]] constexpr Vector3<T> Cross(const Vector3<T>& lhs, const Vector3<T>& rhs)
{
    return Vector3<T>((lhs.y * rhs.z) - (lhs.z * rhs.y), (lhs.z * rhs.x) - (lhs.x * rhs.z), (lhs.x * rhs.y) - (lhs.y * rhs.x));
}

template <typename T>
class Vector4
{
public:
    constexpr Vector4() = default;
    constexpr Vector4(T x, T y, T z, T w);

    template <typename U>
    constexpr explicit operator Vector4<U>() const
    {
        return Vector4<U>(static_cast<U>(x), static_cast<U>(y), static_cast<U>(z), static_cast<U>(w));
    }

    [[nodiscard]] constexpr T Length() const { return std::sqrt(SquaredLength()); }
    [[nodiscard]] constexpr T SquaredLength() const { return x * x + y * y + z * z + w * w; }
    [[nodiscard]] constexpr Vector4 Normalized() const { return *this / Length(); }

    T x{};
    T y{};
    T z{};
    T w{};
};

// Operator Overloads

template <typename T>
[[nodiscard]] constexpr Vector4<T> operator-(Vector4<T> operand)
{
    return Vector4<T>(-operand.x, -operand.y, -operand.z, -operand.w);
}

template <typename T>
[[nodiscard]] constexpr Vector4<T> operator+(Vector4<T> lhs, Vector4<T> rhs)
{
    return Vector4<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w);
}

template <typename T>
[[nodiscard]] constexpr Vector4<T> operator-(Vector4<T> lhs, Vector4<T> rhs)
{
    return Vector4<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w);
}

template <typename T>
[[nodiscard]] constexpr Vector4<T> operator*(Vector4<T> lhs, Vector4<T> rhs)
{
    return Vector4<T>(lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z, lhs.w * rhs.w);
}

template <typename T>
[[nodiscard]] constexpr Vector4<T> operator*(T lhs, Vector4<T> rhs)
{
    return Vector4<T>(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.w * lhs);
}

template <typename T>
[[nodiscard]] constexpr Vector4<T> operator*(Vector4<T> lhs, T rhs)
{
    return Vector4<T>(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs, lhs.w * rhs);
}

template <typename T>
[[nodiscard]] constexpr Vector4<T> operator/(Vector4<T> lhs, T rhs)
{
    assert((rhs != 0) && "Division By Zero");
    return Vector4<T>(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs, lhs.w / rhs);
}

template <typename T>
constexpr Vector4<T>& operator+=(Vector4<T>& lhs, Vector4<T> rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
    lhs.w += rhs.w;
    return lhs;
}

template <typename T>
constexpr Vector4<T>& operator-=(Vector4<T>& lhs, Vector4<T> rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
    lhs.w -= rhs.w;
    return lhs;
}

template <typename T>
constexpr Vector4<T>& operator*=(Vector4<T>& lhs, T rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    lhs.z *= rhs;
    lhs.w *= rhs;
    return lhs;
}

template <typename T>
constexpr Vector4<T>& operator/=(Vector4<T>& lhs, T rhs)
{
    assert((rhs != 0) && "Division by Zero");
    lhs.x /= rhs;
    lhs.y /= rhs;
    lhs.z /= rhs;
    lhs.w /= rhs;
    return lhs;
}

template <typename T>
[[nodiscard]] constexpr bool operator==(Vector4<T> lhs, Vector4<T> rhs)
{
    return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
}

template <typename T>
[[nodiscard]] constexpr bool operator!=(Vector4<T> lhs, Vector4<T> rhs)
{
    return !(lhs == rhs);
}

// Helper Functions

template <typename T>
[[nodiscard]] constexpr T Dot(const Vector4<T>& lhs, const Vector4<T>& rhs)
{
    return (lhs.x * rhs.x) + (lhs.y * rhs.y) + (lhs.z * rhs.z) + (lhs.w * rhs.w);
}

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

template <typename T>
struct std::formatter<Ren::Vector2<T>> : std::formatter<T>
{
    auto format(const Ren::Vector2<T>& vec, std::format_context& ctx)
    {
        return std::format_to(ctx.out(), "[{}, {}]", vec.x, vec.y);
    }
};

template <typename T>
struct std::formatter<Ren::Vector3<T>> : std::formatter<T>
{
    auto format(const Ren::Vector3<T>& vec, std::format_context& ctx)
    {
        return std::format_to(ctx.out(), "[{}, {}, {}]", vec.x, vec.y, vec.z);
    }
};

template <typename T>
struct std::formatter<Ren::Vector4<T>> : std::formatter<T>
{
    auto format(const Ren::Vector4<T>& vec, std::format_context& ctx)
    {
        return std::format_to(ctx.out(), "[{}, {}, {}, {}]", vec.x, vec.y, vec.z, vec.w);
    }
};
