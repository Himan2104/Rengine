#pragma once

#include <Rengine/Core/Definitions.hxx>
#include <Rengine/Core/String.hxx>
#include <imgui.h>

namespace Ren::Editor
{

enum class StatusItemAlignment : UInt8
{
    Center = 0,
    Left   = 1,
    Right  = 2
};

class IStatusProvider
{
public:
    virtual ~IStatusProvider()                       = default;
    virtual void Render()                            = 0;
    virtual StatusItemAlignment GetAlignment() const = 0;
    virtual UInt8 GetOrder() const                   = 0;
    virtual Float32 GetWidth() const                 = 0;
    virtual std::string_view GetName() const         = 0;
};

template <FixedString name, UInt8 order, StatusItemAlignment alignment>
class StatusProvider : public IStatusProvider
{
public:
    StatusItemAlignment GetAlignment() const override { return alignment; }
    UInt8 GetOrder() const override { return order; }
    std::string_view GetName() const override { return name; }
};
} // namespace Ren::Editor
