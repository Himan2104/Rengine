#pragma once

#include <imgui.h>

namespace Ren::Editor
{

class IMenuProvider
{
public:
    virtual ~IMenuProvider()                = default;
    virtual void RenderMenu()               = 0;
    virtual const char* GetMenuName() const = 0;
    virtual int GetMenuPriority() const { return 100; } // Lower = earlier in menu bar
};
} // namespace Ren::Editor
