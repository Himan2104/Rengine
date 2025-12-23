#pragma once

#include <Rengine/Core/Types.hxx>
#include <functional>
#include <optional>
#include <vector>

namespace Ren
{

template <typename T, UInt64 size>
class Array
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

template <typename T, typename Allocator = std::allocator<T>>
class DynamicArray : private std::vector<T, Allocator>
{
private:
    using Base     = std::vector<T, Allocator>;
    using SizeType = typename Base::size_type;

public:
    using value_type     = T;
    using allocator_type = Allocator;
    using iterator       = typename Base::iterator;
    using const_iterator = typename Base::const_iterator;

    using Base::begin;
    using Base::end;

    constexpr DynamicArray() = default;

    constexpr explicit DynamicArray(const Allocator& alloc)
        : Base(alloc)
    {
    }

    constexpr DynamicArray(std::initializer_list<T> init, const Allocator& alloc = Allocator{})
        : Base(init, alloc)
    {
    }

    constexpr explicit DynamicArray(SizeType count, const Allocator& alloc = Allocator{})
        : Base(count, alloc)
    {
    }

    constexpr DynamicArray(SizeType count, const T& value, const Allocator& alloc = Allocator{})
        : Base(count, value, alloc)
    {
    }

    [[nodiscard]]
    constexpr const Allocator& GetAllocator() const noexcept
    {
        return Base::get_allocator();
    }

    void PushBack(const T& value) { Base::push_back(value); }

    void PushBack(T&& value) { Base::push_back(std::move(value)); }

    template <typename... Args>
    void EmplaceBack(Args&&... args)
    {
        Base::emplace_back(std::forward<Args>(args)...);
    }

    template <typename... Args>
    typename Base::iterator Emplace(const_iterator pos, Args&&... args)
    {
        return Base::emplace(pos, std::forward<Args>(args)...);
    }

    [[nodiscard]]
    std::optional<T> PopBack() noexcept
    {
        if (Base::empty()) return std::nullopt;

        T value = std::move(Base::back());
        Base::pop_back();

        if constexpr (std::is_pointer_v<T>)
            return value ? std::optional<T>(std::move(value)) : std::nullopt;
        else
            return std::optional<T>(std::move(value));
    }

    constexpr void Clear() noexcept { Base::clear(); }

    [[nodiscard]]
    constexpr SizeType Size() const noexcept
    {
        return Base::size();
    }

    [[nodiscard]]
    constexpr bool IsEmpty() const noexcept
    {
        return Base::empty();
    }

    [[nodiscard]]
    constexpr T& At(SizeType index)
    {
        return Base::at(index);
    }

    [[nodiscard]]
    constexpr const T& At(SizeType index) const
    {
        return Base::at(index);
    }

    constexpr T& operator[](SizeType index) { return Base::operator[](index); }

    constexpr const T& operator[](SizeType index) const { return Base::operator[](index); }

    [[nodiscard]]
    constexpr T& Front() noexcept
    {
        return Base::front();
    }

    [[nodiscard]]
    constexpr const T& Front() const noexcept
    {
        return Base::front();
    }

    [[nodiscard]]
    constexpr T& Back() noexcept
    {
        return Base::back();
    }

    [[nodiscard]]
    constexpr const T& Back() const noexcept
    {
        return Base::back();
    }

    [[nodiscard]]
    constexpr T* Data() noexcept
    {
        return Base::data();
    }

    [[nodiscard]]
    constexpr const T* Data() const noexcept
    {
        return Base::data();
    }

    [[nodiscard]]
    constexpr iterator Begin() noexcept
    {
        return Base::begin();
    }

    [[nodiscard]]
    constexpr const_iterator Begin() const noexcept
    {
        return Base::begin();
    }

    [[nodiscard]]
    constexpr iterator End() noexcept
    {
        return Base::end();
    }

    [[nodiscard]]
    constexpr const_iterator End() const noexcept
    {
        return Base::end();
    }
};

} // namespace Ren
