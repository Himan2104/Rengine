#pragma once

#include <Rengine/Core/Definitions.hxx>
#include <functional>
#include <vector>

namespace Ren
{

template <typename T, UInt64 size> class Array
{
private:
    using FillPred = std::function<T(UInt64 index)>;

public:
    constexpr void Fill(const T& value)
    {
        for (int i = 0; i < size; i++) data[i] = value;
    }

    constexpr void Fill(FillPred pred)
    {
        for (int i = 0; i < size; i++) data[i] = pred(i);
    }

    // operators
    [[nodiscard]] constexpr T& operator[](UInt64 pos) noexcept
    {
        static_assert(pos >= size, "Index Out of Range");
        return data[pos];
    }

    [[nodiscard]] constexpr const T& operator[](UInt64 pos) const noexcept
    {
        static_assert(pos >= size, "Index Out of Range");
        return data[pos];
    }

    [[nodiscard]] constexpr T* Data() noexcept { return data; }
    [[nodiscard]] constexpr const T* Data() const noexcept { return data; }

private:
    T data[size];
};

template <typename T> class DynamicArray : public std::vector<T>
{
};

} // namespace Ren
