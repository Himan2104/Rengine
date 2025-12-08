#include "InBuiltEditorWindows/ThemeEditor.hxx"
#include "Rengine/Core/Definitions.hxx"
#include "Rengine/Core/Log.hxx"
#include "Rengine/Editor/StatusProvider.hxx"
#include "Rengine/Graphics/RenderFlags.hxx"
#include "imgui-SFML.h"
#include <Rengine/Editor/EditorUI.hxx>
#include <Rengine/Editor/Icons.hxx>
#include <cstddef>
#include <imgui.h>

namespace Ren::Editor
{

EditorUI::EditorUI()
{
    ImGuiIO& io = ImGui::GetIO();

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

    io.Fonts->Clear();

    ImFontConfig config;
    // config.PixelSnapH = true;
    //  config.GlyphOffset.x          = 3.0f;
    static const ImWchar ranges[] = {0x0020,   0x00FF,   // Basic Latin + Latin Supplement
                                     0x0100,   0x017F,   // Latin Extended-A
                                     0x0180,   0x024F,   // Latin Extended-B
                                     0x1E00,   0x1EFF,   // Latin Extended Additional
                                     ICON_MIN, ICON_MAX, // NerdFont icons
                                     0};
    io.Fonts->AddFontFromFileTTF("Assets/Fonts/0xProtoNerdFont-Regular.ttf", 16.0f, &config, ranges);

    io.Fonts->Build();
    if (!ImGui::SFML::UpdateFontTexture()) REN_LOG_ERROR("ImGui::SFML::UpdateFontTexture returned false");

    ImGui::StyleColorsDark();

    ImGuiStyle& style = ImGui::GetStyle();
    if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
    {
        style.WindowRounding              = 0.0f;
        style.Colors[ImGuiCol_WindowBg].w = 1.0f;
    }

    style.Alpha                     = 1.0f;
    style.DisabledAlpha             = 1.0f;
    style.WindowPadding             = ImVec2(12.0f, 12.0f);
    style.WindowRounding            = 0.0f;
    style.WindowBorderSize          = 0.0f;
    style.WindowMinSize             = ImVec2(20.0f, 20.0f);
    style.WindowTitleAlign          = ImVec2(0.5f, 0.5f);
    style.WindowMenuButtonPosition  = ImGuiDir_None;
    style.ChildRounding             = 0.0f;
    style.ChildBorderSize           = 1.0f;
    style.PopupRounding             = 0.0f;
    style.PopupBorderSize           = 1.0f;
    style.FramePadding              = ImVec2(6.0f, 6.0f);
    style.FrameRounding             = 0.0f;
    style.FrameBorderSize           = 0.0f;
    style.ItemSpacing               = ImVec2(12.0f, 6.0f);
    style.ItemInnerSpacing          = ImVec2(6.0f, 3.0f);
    style.CellPadding               = ImVec2(12.0f, 6.0f);
    style.IndentSpacing             = 20.0f;
    style.ColumnsMinSpacing         = 6.0f;
    style.ScrollbarSize             = 12.0f;
    style.ScrollbarRounding         = 0.0f;
    style.GrabMinSize               = 12.0f;
    style.GrabRounding              = 0.0f;
    style.TabRounding               = 0.0f;
    style.TabBorderSize             = 0.0f;
    style.TabMinWidthForCloseButton = 0.0f;
    style.ColorButtonPosition       = ImGuiDir_Right;
    style.ButtonTextAlign           = ImVec2(0.5f, 0.5f);
    style.SelectableTextAlign       = ImVec2(0.0f, 0.0f);

    style.Colors[ImGuiCol_Text]                  = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.2745f, 0.3176f, 0.4509f, 1.0f);
    style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.0784f, 0.0862f, 0.1019f, 1.0f);
    style.Colors[ImGuiCol_ChildBg]               = ImVec4(0.0784f, 0.0862f, 0.1019f, 1.0f);
    style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.0784f, 0.0862f, 0.1019f, 1.0f);
    style.Colors[ImGuiCol_Border]                = ImVec4(0.1568f, 0.1686f, 0.1921f, 1.0f);
    style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.0784f, 0.0862f, 0.1019f, 1.0f);
    style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.1176f, 0.1333f, 0.1490f, 1.0f);
    style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.1568f, 0.1686f, 0.1921f, 1.0f);
    style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.2352f, 0.2156f, 0.5960f, 1.0f);
    style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.0470f, 0.0549f, 0.0705f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.0470f, 0.0549f, 0.0705f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.0784f, 0.0862f, 0.1019f, 1.0f);
    style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.0980f, 0.1058f, 0.1215f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.0470f, 0.0549f, 0.0705f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.1176f, 0.1333f, 0.1490f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.1568f, 0.1686f, 0.1921f, 1.0f);
    style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.1176f, 0.1333f, 0.1490f, 1.0f);
    style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.4980f, 0.5137f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.4980f, 0.5137f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.5372f, 0.5529f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_Button]                = ImVec4(0.1176f, 0.1333f, 0.1490f, 1.0f);
    style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.1960f, 0.1764f, 0.5450f, 1.0f);
    style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.2352f, 0.2156f, 0.5960f, 1.0f);
    style.Colors[ImGuiCol_Header]                = ImVec4(0.1176f, 0.1333f, 0.1490f, 1.0f);
    style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.1960f, 0.1764f, 0.5450f, 1.0f);
    style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.2352f, 0.2156f, 0.5960f, 1.0f);
    style.Colors[ImGuiCol_Separator]             = ImVec4(0.1568f, 0.1843f, 0.2509f, 1.0f);
    style.Colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.1568f, 0.1843f, 0.2509f, 1.0f);
    style.Colors[ImGuiCol_SeparatorActive]       = ImVec4(0.1568f, 0.1843f, 0.2509f, 1.0f);
    style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.1176f, 0.1333f, 0.1490f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.1960f, 0.1764f, 0.5450f, 1.0f);
    style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.2352f, 0.2156f, 0.5960f, 1.0f);
    style.Colors[ImGuiCol_Tab]                   = ImVec4(0.0470f, 0.0549f, 0.0705f, 1.0f);
    style.Colors[ImGuiCol_TabHovered]            = ImVec4(0.1176f, 0.1333f, 0.1490f, 1.0f);
    style.Colors[ImGuiCol_TabActive]             = ImVec4(0.0980f, 0.1058f, 0.1215f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocused]          = ImVec4(0.0470f, 0.0549f, 0.0705f, 1.0f);
    style.Colors[ImGuiCol_TabUnfocusedActive]    = ImVec4(0.0784f, 0.0862f, 0.1019f, 1.0f);
    style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.5215f, 0.6000f, 0.7019f, 1.0f);
    style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.0392f, 0.9803f, 0.9803f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(1.0f, 0.2901f, 0.5960f, 1.0f);
    style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.9960f, 0.4745f, 0.6980f, 1.0f);
    style.Colors[ImGuiCol_TableHeaderBg]         = ImVec4(0.0470f, 0.0549f, 0.0705f, 1.0f);
    style.Colors[ImGuiCol_TableBorderStrong]     = ImVec4(0.0470f, 0.0549f, 0.0705f, 1.0f);
    style.Colors[ImGuiCol_TableBorderLight]      = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    style.Colors[ImGuiCol_TableRowBg]            = ImVec4(0.1176f, 0.1333f, 0.1490f, 1.0f);
    style.Colors[ImGuiCol_TableRowBgAlt]         = ImVec4(0.0980f, 0.1058f, 0.1215f, 1.0f);
    style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.2352f, 0.2156f, 0.5960f, 1.0f);
    style.Colors[ImGuiCol_DragDropTarget]        = ImVec4(0.4980f, 0.5137f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_NavHighlight]          = ImVec4(0.4980f, 0.5137f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(0.4980f, 0.5137f, 1.0f, 1.0f);
    style.Colors[ImGuiCol_NavWindowingDimBg]     = ImVec4(0.1960f, 0.1764f, 0.5450f, 0.5019f);
    style.Colors[ImGuiCol_ModalWindowDimBg]      = ImVec4(0.1960f, 0.1764f, 0.5450f, 0.5019f);

    LoadDefaultWindowsAndProviders();
}

void EditorUI::RenderFrame()
{
    ImGuiViewport* viewport = ImGui::GetMainViewport();

    // Adjust dockspace to exclude status bar area
    ImVec2 dockspace_pos  = viewport->WorkPos;
    ImVec2 dockspace_size = ImVec2(viewport->WorkSize.x, viewport->WorkSize.y - kStatusBarHeight);

    // Set window to cover viewport minus status bar
    ImGui::SetNextWindowPos(dockspace_pos);
    ImGui::SetNextWindowSize(dockspace_size);
    ImGui::SetNextWindowViewport(viewport->ID);

    // Configure window flags for dockspace
    ImGuiWindowFlags host_window_flags = 0;
    host_window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse;
    host_window_flags |= ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    host_window_flags |= ImGuiWindowFlags_NoDocking;
    host_window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
    host_window_flags |= ImGuiWindowFlags_NoBackground;

    // Configure dockspace flags
    ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
    dockspace_flags |= ImGuiDockNodeFlags_PassthruCentralNode;

    // Push window styling
    ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

    // Create the dockspace host window
    if (ImGui::Begin("DockSpaceWindow", nullptr, host_window_flags))
    {
        ImGui::PopStyleVar(3);

        // Create the dockspace
        ImGuiID dockspace_id = ImGui::GetID("MainDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);

        // Render menu bar inside the dockspace
        RenderMenuBar();
    }
    else
    {
        ImGui::PopStyleVar(3);
    }
    ImGui::End();
    RenderStatusBar();
    RenderWindows();
}

void EditorUI::RenderMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        ImGui::Button(ICON_FA_HOME " ");

        for (auto& provider : _menuProviders) { provider->RenderMenu(); }

        ImGui::EndMainMenuBar();
    }
}

void EditorUI::RenderWindows()
{
    for (auto& window : _editorWindows)
    {
        if (window->IsVisible())
        {
            bool visible = true;
            if (ImGui::Begin(window->GetName().data(), &visible, window->GetWindowFlags())) { window->Render(); }

            if (!visible && window->IsVisible())
            {
                window->SetVisible(false);
                window->OnWindowClosed();
            }

            ImGui::End();
        }
    }
}

void EditorUI::RenderStatusBar()
{
    ImGuiViewport* viewport = ImGui::GetMainViewport();
    ImVec2 work_pos         = viewport->WorkPos;
    ImVec2 work_size        = viewport->WorkSize;

    ImGui::SetNextWindowPos(ImVec2(work_pos.x, work_pos.y + work_size.y - kStatusBarHeight));
    ImGui::SetNextWindowSize(ImVec2(work_size.x, kStatusBarHeight));

    ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoDocking;

    if (ImGui::Begin("StatusBar", nullptr, window_flags)) { RenderStatusBarContent(); }
    ImGui::End();
}

void EditorUI::RenderStatusBarContent()
{
    if (_statusProviders.IsEmpty()) return;

    float totalWidth     = ImGui::GetContentRegionAvail().x;
    size_t providerCount = _statusProviders.Size();
    float textHeight     = ImGui::GetTextLineHeight();
    float verticalCenter = (kStatusBarHeight - textHeight) * 0.5f;

    // Edge alignment with proper bounds checking
    float leftMargin  = 8.0f;
    float rightMargin = 50.0f; // Increased to account for text width of last element

    if (providerCount == 1)
    {
        // Single item - place at left margin
        ImGui::SetCursorPos({leftMargin, verticalCenter});
        ImGui::BeginGroup();
        _statusProviders[0]->Render();
        ImGui::EndGroup();
        return;
    }

    // Calculate spacing for edge alignment with proper bounds
    float usableWidth = totalWidth - leftMargin - rightMargin;
    float spacing     = usableWidth / (providerCount - 1);

    for (size_t i = 0; i < providerCount; ++i)
    {
        float xPos;

        if (i == 0)
        {
            // First element - at left margin
            xPos = leftMargin;
        }
        else if (i == providerCount - 1)
        {
            // Last element - positioned from right edge accounting for text width
            xPos = totalWidth - rightMargin;
        }
        else
        {
            // Middle elements - evenly distributed
            xPos = leftMargin + (i * spacing);
        }

        if (i == 0) { ImGui::SetCursorPos({xPos, verticalCenter}); }
        else
        {
            ImGui::SameLine();
            ImGui::SetCursorPos({xPos, verticalCenter});
        }

        ImGui::BeginGroup();
        _statusProviders[i]->Render();
        ImGui::EndGroup();
    }
}

void EditorUI::LoadDefaultWindowsAndProviders() { AddWindow(std::make_unique<IBEW::ThemeEditor>()); }

void EditorUI::AddWindow(std::unique_ptr<IEditorWindow> window) { _editorWindows.PushBack(std::move(window)); }

void EditorUI::AddMenuProvider(std::unique_ptr<IMenuProvider> provider)
{
    _menuProviders.PushBack(std::move(provider));
    std::sort(_menuProviders.begin(), _menuProviders.end(),
              [](auto& a, auto& b) { return a->GetPriority() < b->GetPriority(); });
}

void EditorUI::AddStatusProvider(std::unique_ptr<IStatusProvider> provider) { _statusProviders.PushBack(std::move(provider)); }

void EditorUI::ShowWindow(const std::string& windowName, bool show)
{
    for (auto& window : _editorWindows)
    {
        if (window->GetName() == windowName)
        {
            bool wasVisible = window->IsVisible();
            window->SetVisible(show);
            if (!wasVisible && show) { window->OnWindowOpened(); }
            else if (wasVisible && !show) { window->OnWindowClosed(); }
            break;
        }
    }

    REN_LOG_WARNING("");
}

} // namespace Ren::Editor
