#pragma once

#include <Rengine/Core/Types.hxx>
#include <Rengine/Core/String.hxx>
#include <imgui.h>

namespace Ren::Editor
{

class IStatusProvider
{
public:
    virtual ~IStatusProvider()               = default;
    virtual void Render()                    = 0;
    virtual UInt8 GetOrder() const           = 0;
    virtual Float32 GetWidth() const         = 0;
    virtual std::string_view GetName() const = 0;
};

template <FixedString name, UInt8 order>
class StatusProvider : public IStatusProvider
{
public:
    UInt8 GetOrder() const override { return order; }
    std::string_view GetName() const override { return name; }
};
} // namespace Ren::Editor
