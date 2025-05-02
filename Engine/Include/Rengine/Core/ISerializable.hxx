#pragma once

#include <string>
#include <string_view>

namespace Ren
{

template <typename T> class ISerializable
{
public:
    virtual std::string Serialize()             = 0;
    virtual T Deserialize(std::string_view str) = 0;
};

} // namespace Ren
