#pragma once

#include <Rengine/Core/Array.hxx>
#include <Rengine/Editor/IEditorWindow.hxx>
#include <Rengine/Editor/IMenuProvider.hxx>
#include <Rengine/Editor/IStatusProvider.hxx>
#include <memory>

namespace Ren::Editor
{

class MainEditorUI
{
private:
    DynamicArray<std::unique_ptr<IEditorWindow>> m_windows;
    DynamicArray<std::unique_ptr<IMenuProvider>> m_menuProviders;
    DynamicArray<std::unique_ptr<IStatusProvider>> m_statusProviders;

    // System info
    float m_cpuUsage     = 0.0f;
    size_t m_memoryUsage = 0;
    size_t m_totalMemory = 0;

    void RenderMenuBar();
    void RenderStatusBar();
    void RenderWindows();

public:
    MainEditorUI();
    ~MainEditorUI() = default;

    // Main render function - call this every frame
    void RenderFrame();

    // Window management
    void AddWindow(std::unique_ptr<IEditorWindow> window);
    void RemoveWindow(const std::string& windowName);
    IEditorWindow* GetWindow(const std::string& windowName);

    // Menu management
    void AddMenuProvider(std::unique_ptr<IMenuProvider> provider);
    void RemoveMenuProvider(const std::string& menuName);

    // Status bar management
    void AddStatusProvider(std::unique_ptr<IStatusProvider> provider);
    void RemoveStatusProvider(IStatusProvider* provider);

    // Utility functions
    void ShowWindow(const std::string& windowName, bool show = true);
    void ToggleWindow(const std::string& windowName);
};

} // namespace Ren::Editor
