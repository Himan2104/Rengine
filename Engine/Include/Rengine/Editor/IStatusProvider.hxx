#pragma once

#include <imgui.h>

namespace Ren::Editor
{

class IStatusProvider
{
public:
    virtual ~IStatusProvider()  = default;
    virtual void RenderStatus() = 0;
    virtual int GetStatusPriority() const { return 100; }  // Lower = left side
    virtual float GetStatusWidth() const { return -1.0f; } // -1 = auto width
};
} // namespace Ren::Editor
