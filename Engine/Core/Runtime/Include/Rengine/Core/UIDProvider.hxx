#pragma once

#include <Rengine/Core/Array.hxx>

namespace Ren
{

template <typename T> class UIDProvider final
{
public:
    constexpr UIDProvider() = default;

    [[nodiscard]] constexpr T GetNewUID() { return _freeIDs.IsEmpty() ? _counter++ : _freeIDs.PopBack().value(); }

    void FreeID(T id) { _freeIDs.push_back(id); }

private:
    DynamicArray<T> _freeIDs;
    T _counter{};
};

} // namespace Ren
