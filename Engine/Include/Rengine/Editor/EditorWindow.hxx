#pragma once

#include <Rengine/Core/String.hxx>
#include <imgui.h>

namespace Ren::Editor
{

class IEditorWindow
{
public:
    virtual ~IEditorWindow()                 = default;
    virtual void Render()                    = 0;
    virtual std::string_view GetName() const = 0;
    virtual bool IsVisible() const           = 0;
    virtual void SetVisible(bool visible)    = 0;
    virtual ImGuiWindowFlags GetWindowFlags() const { return ImGuiWindowFlags_None; }
    virtual void OnWindowClosed() {}
    virtual void OnWindowOpened() {}
};

template <FixedString name, ImGuiWindowFlags windowFlags>
class EditorWindow : public IEditorWindow
{
public:
    std::string_view GetName() const override { return name; }
    ImGuiWindowFlags GetWindowFlags() const override { return windowFlags; }
    bool IsVisible() const override { return _visibility; }
    void SetVisible(bool visible) override { _visibility = visible; }

private:
    bool _visibility = true;
};
} // namespace Ren::Editor
