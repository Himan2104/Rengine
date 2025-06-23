#pragma once

#include <vector>

namespace Ren
{

template <typename T> class UIDProvider final
{
public:
    constexpr UIDProvider() = default;

    [[nodiscard]] constexpr T GetNewUID() { return _freeIDs.empty() ? _counter++ : _freeIDs.pop_back(); }

    void FreeID(T id) { _freeIDs.push_back(id); }

private:
    std::vector<T> _freeIDs;
    T _counter{};
};

} // namespace Ren
