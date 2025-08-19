#pragma once

#include <Rengine/Core/Array.hxx>
#include <Rengine/Core/Definitions.hxx>
#include <Rengine/Editor/EditorWindow.hxx>
#include <Rengine/Editor/MenuProvider.hxx>
#include <Rengine/Editor/StatusProvider.hxx>
#include <memory>

namespace Ren::Editor
{

class MainEditorUI
{
private:
    constexpr static Float32 STATUS_BAR_HEIGHT = 25.0f;
    DynamicArray<std::unique_ptr<IEditorWindow>> _editorWindows;
    DynamicArray<std::unique_ptr<IMenuProvider>> _menuProviders;
    DynamicArray<std::unique_ptr<IStatusProvider>> _statusProvidersLeftAligned;
    DynamicArray<std::unique_ptr<IStatusProvider>> _statusProvidersRightAligned;
    DynamicArray<std::unique_ptr<IStatusProvider>> _statusProvidersCenterAligned;

    // System info
    float m_cpuUsage     = 0.0f;
    size_t m_memoryUsage = 0;
    size_t m_totalMemory = 0;

    void RenderMenuBar();
    void RenderStatusBar();
    void RenderWindows();

    void RenderStatusBarContent();
    void RenderStatusGroup(const DynamicArray<std::unique_ptr<IStatusProvider>>& providers);
    Float32 CalculateGroupWidth(const DynamicArray<std::unique_ptr<IStatusProvider>>& providers);

public:
    MainEditorUI();
    ~MainEditorUI() = default;

    void RenderFrame();

    void AddWindow(std::unique_ptr<IEditorWindow> window);
    void RemoveWindow(const std::string& windowName);
    IEditorWindow* GetWindow(const std::string& windowName);

    void AddMenuProvider(std::unique_ptr<IMenuProvider> provider);
    void RemoveMenuProvider(const std::string& menuName);

    void AddStatusProvider(std::unique_ptr<IStatusProvider> provider);
    void RemoveStatusProvider(IStatusProvider* provider);

    void ShowWindow(const std::string& windowName, bool show = true);
    void ToggleWindow(const std::string& windowName);
};

} // namespace Ren::Editor
