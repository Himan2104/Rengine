#pragma once

#include <Rengine/Core/Types.hxx>
#include <Rengine/Core/String.hxx>
#include <imgui.h>

namespace Ren::Editor
{

class IMenuProvider
{
public:
    virtual ~IMenuProvider()                 = default;
    virtual void RenderMenu()                = 0;
    virtual std::string_view GetName() const = 0;
    virtual UInt8 GetPriority() const { return 100; }
};

template <FixedString name, UInt8 priority>
class MenuProvider : public IMenuProvider
{
    std::string_view GetName() const override { return name; }
    UInt8 GetPriority() const override { return priority; }
};
} // namespace Ren::Editor
