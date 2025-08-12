#pragma once

#include <imgui.h>

namespace Ren::Editor
{

class IEditorWindow
{
public:
    virtual ~IEditorWindow()                  = default;
    virtual void Render()                     = 0;
    virtual const char* GetWindowName() const = 0;
    virtual bool IsVisible() const            = 0;
    virtual void SetVisible(bool visible)     = 0;
    virtual ImGuiWindowFlags GetWindowFlags() const { return ImGuiWindowFlags_None; }
    virtual void OnWindowClosed() {}
    virtual void OnWindowOpened() {}
};
} // namespace Ren::Editor
