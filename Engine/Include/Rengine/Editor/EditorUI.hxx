#pragma once

#include <Rengine/Core/Array.hxx>
#include <Rengine/Core/Definitions.hxx>
#include <Rengine/Editor/EditorWindow.hxx>
#include <Rengine/Editor/MenuProvider.hxx>
#include <Rengine/Editor/StatusProvider.hxx>
#include <memory>
#include <string>

namespace Ren::Editor
{

class EditorUI
{
public:
    EditorUI();
    ~EditorUI() = default;

    void Initialize();

    void RenderFrame();

    Bool IsInitialized() const { return _initialized; }

    void AddWindow(std::unique_ptr<IEditorWindow> window);
    void RemoveWindow(const std::string& windowName);
    IEditorWindow* GetWindow(const std::string& windowName);

    void AddMenuProvider(std::unique_ptr<IMenuProvider> provider);
    void RemoveMenuProvider(const std::string& menuName);

    void AddStatusProvider(std::unique_ptr<IStatusProvider> provider);
    void RemoveStatusProvider(IStatusProvider* provider);

    void ShowWindow(const std::string& windowName, bool show = true);
    void ToggleWindow(const std::string& windowName);

    void SetTheme();

private:
    void LoadFonts();

    void RenderMenuBar();
    void RenderStatusBar();
    void RenderWindows();

    void RenderStatusBarContent();

    void LoadDefaultWindowsAndProviders();

public:
    constexpr static Float32 kStatusBarHeight = 25.0f;

private:
    DynamicArray<std::unique_ptr<IEditorWindow>> _editorWindows;
    DynamicArray<std::unique_ptr<IMenuProvider>> _menuProviders;
    DynamicArray<std::unique_ptr<IStatusProvider>> _statusProviders;

    Bool _initialized{false};

    // System info
    float m_cpuUsage     = 0.0f;
    size_t m_memoryUsage = 0;
    size_t m_totalMemory = 0;
};

} // namespace Ren::Editor
