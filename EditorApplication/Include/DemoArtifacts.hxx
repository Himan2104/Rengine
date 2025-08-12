#pragma once

#include "Rengine/Core/Log.hxx"
#include <Rengine/Editor/IEditorWindow.hxx>
#include <Rengine/Editor/IMenuProvider.hxx>
#include <Rengine/Editor/IStatusProvider.hxx>
#include <chrono>
#include <string>
#include <vector>

namespace Ren::Editor
{
// Example 1: Properties Window
class PropertiesWindow : public IEditorWindow
{
private:
    bool m_visible         = true;
    float m_floatValue     = 0.0f;
    int m_intValue         = 0;
    ImVec4 m_colorValue    = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
    char m_textBuffer[256] = "Hello World";

public:
    void Render() override
    {
        ImGui::Text("Properties Editor");
        ImGui::Separator();

        ImGui::SliderFloat("Float Property", &m_floatValue, 0.0f, 100.0f);
        ImGui::SliderInt("Int Property", &m_intValue, 0, 100);
        ImGui::ColorEdit4("Color Property", (float*)&m_colorValue);
        ImGui::InputText("Text Property", m_textBuffer, sizeof(m_textBuffer));

        if (ImGui::Button("Reset Values"))
        {
            m_floatValue = 0.0f;
            m_intValue   = 0;
            m_colorValue = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
            strcpy(m_textBuffer, "Hello World");
        }
    }

    const char* GetWindowName() const override { return "Properties"; }
    bool IsVisible() const override { return m_visible; }
    void SetVisible(bool visible) override { m_visible = visible; }
};

// Example 2: Scene Hierarchy Window
class SceneHierarchyWindow : public IEditorWindow
{
private:
    bool m_visible                         = true;
    std::vector<std::string> m_gameObjects = {"Main Camera", "Directional Light", "Player",        "Enemy1",      "Enemy2",
                                              "Terrain",     "UI Canvas",         "Audio Manager", "Game Manager"};
    int m_selectedObject                   = -1;

public:
    void Render() override
    {
        ImGui::Text("Scene Hierarchy");
        ImGui::Separator();

        for (int i = 0; i < m_gameObjects.size(); ++i)
        {
            bool isSelected = (m_selectedObject == i);
            if (ImGui::Selectable(m_gameObjects[i].c_str(), isSelected)) { m_selectedObject = i; }

            if (ImGui::BeginPopupContextItem())
            {
                if (ImGui::MenuItem("Delete"))
                {
                    m_gameObjects.erase(m_gameObjects.begin() + i);
                    m_selectedObject = -1;
                }
                if (ImGui::MenuItem("Duplicate"))
                {
                    m_gameObjects.insert(m_gameObjects.begin() + i + 1, m_gameObjects[i] + " Copy");
                }
                ImGui::EndPopup();
            }
        }

        ImGui::Separator();
        if (ImGui::Button("Add GameObject")) { m_gameObjects.push_back("New GameObject"); }
    }

    const char* GetWindowName() const override { return "Scene Hierarchy"; }
    bool IsVisible() const override { return m_visible; }
    void SetVisible(bool visible) override { m_visible = visible; }
};

// Example 3: Console Window
class ConsoleWindow : public IEditorWindow
{
private:
    bool m_visible = true;
    std::vector<std::string> m_logs;
    char m_inputBuffer[256] = "";
    bool m_autoScroll       = true;

public:
    ConsoleWindow()
    {
        m_logs.push_back("[INFO] Console initialized");
        m_logs.push_back("[DEBUG] System ready");
    }

    void Render() override
    {
        ImGui::Text("Console");
        ImGui::SameLine();
        if (ImGui::SmallButton("Clear")) { m_logs.clear(); }
        ImGui::SameLine();
        ImGui::Checkbox("Auto-scroll", &m_autoScroll);

        ImGui::Separator();

        // Log display
        ImGui::BeginChild("ScrollingRegion", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), false,
                          ImGuiWindowFlags_HorizontalScrollbar);

        for (const auto& log : m_logs)
        {
            ImVec4 color = ImVec4(1, 1, 1, 1);
            if (log.find("[ERROR]") != std::string::npos)
                color = ImVec4(1, 0.4f, 0.4f, 1);
            else if (log.find("[WARN]") != std::string::npos)
                color = ImVec4(1, 1, 0.4f, 1);
            else if (log.find("[DEBUG]") != std::string::npos)
                color = ImVec4(0.7f, 0.7f, 0.7f, 1);

            ImGui::PushStyleColor(ImGuiCol_Text, color);
            ImGui::TextWrapped("%s", log.c_str());
            ImGui::PopStyleColor();
        }

        if (m_autoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) { ImGui::SetScrollHereY(1.0f); }

        ImGui::EndChild();

        // Command input
        if (ImGui::InputText("Command", m_inputBuffer, sizeof(m_inputBuffer), ImGuiInputTextFlags_EnterReturnsTrue))
        {
            if (strlen(m_inputBuffer) > 0)
            {
                m_logs.push_back(std::string("> ") + m_inputBuffer);
                m_logs.push_back("[INFO] Command executed: " + std::string(m_inputBuffer));
                m_inputBuffer[0] = '\0';
            }
        }
    }

    const char* GetWindowName() const override { return "Console"; }
    bool IsVisible() const override { return m_visible; }
    void SetVisible(bool visible) override { m_visible = visible; }

    void AddLog(const std::string& log)
    {
        auto now    = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        auto tm     = *std::localtime(&time_t);

        char timestamp[64];
        sprintf(timestamp, "[%02d:%02d:%02d] ", tm.tm_hour, tm.tm_min, tm.tm_sec);

        m_logs.push_back(std::string(timestamp) + log);
    }
};

// Example 4: Asset Browser Window
class AssetBrowserWindow : public IEditorWindow
{
private:
    bool m_visible                    = true;
    std::vector<std::string> m_assets = {"player_texture.png",   "enemy_model.fbx",    "background_music.wav",
                                         "ui_font.ttf",          "level_data.json",    "shader_vertex.glsl",
                                         "particle_effect.json", "animation_walk.anim"};
    std::string m_currentFilter       = "";
    char m_filterBuffer[128]          = "";

public:
    void Render() override
    {
        ImGui::Text("Asset Browser");
        ImGui::Separator();

        // Filter
        if (ImGui::InputText("Filter", m_filterBuffer, sizeof(m_filterBuffer)))
        {
            m_currentFilter = std::string(m_filterBuffer);
        }

        ImGui::Separator();

        // Asset grid
        int columns = (int)(ImGui::GetContentRegionAvail().x / 120.0f);
        columns     = std::max(1, columns);

        for (int i = 0; i < m_assets.size(); ++i)
        {
            if (!m_currentFilter.empty() && m_assets[i].find(m_currentFilter) == std::string::npos) { continue; }

            ImGui::BeginGroup();
            ImGui::Button("###asset", ImVec2(100, 80)); // Placeholder for asset thumbnail
            ImGui::TextWrapped("%s", m_assets[i].c_str());
            ImGui::EndGroup();

            if (ImGui::BeginDragDropSource())
            {
                ImGui::SetDragDropPayload("ASSET", m_assets[i].c_str(), m_assets[i].length() + 1);
                ImGui::Text("Dragging %s", m_assets[i].c_str());
                ImGui::EndDragDropSource();
            }

            if ((i + 1) % columns != 0 && i < m_assets.size() - 1) { ImGui::SameLine(); }
        }
    }

    const char* GetWindowName() const override { return "Asset Browser"; }
    bool IsVisible() const override { return m_visible; }
    void SetVisible(bool visible) override { m_visible = visible; }
};

// Example 1: File Menu Provider
class FileMenuProvider : public IMenuProvider
{
public:
    void RenderMenu() override
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New", "Ctrl+N"))
            {
                // Handle new file
            }
            if (ImGui::MenuItem("Open", "Ctrl+O"))
            {
                // Handle open file
            }
            if (ImGui::MenuItem("Save", "Ctrl+S"))
            {
                // Handle save
            }
            if (ImGui::MenuItem("Save As", "Ctrl+Shift+S"))
            {
                // Handle save as
            }
            ImGui::Separator();
            if (ImGui::BeginMenu("Recent Files"))
            {
                ImGui::MenuItem("project1.json");
                ImGui::MenuItem("project2.json");
                ImGui::MenuItem("project3.json");
                ImGui::EndMenu();
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Exit", "Alt+F4")) { REN_LOG_INFO("Attempted Exit!"); }
            ImGui::EndMenu();
        }
    }

    const char* GetMenuName() const override { return "File"; }
    int GetMenuPriority() const override { return 10; }
};

// Example 2: Edit Menu Provider
class EditMenuProvider : public IMenuProvider
{
public:
    void RenderMenu() override
    {
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "Ctrl+Z"))
            {
                // Handle undo
            }
            if (ImGui::MenuItem("Redo", "Ctrl+Y"))
            {
                // Handle redo
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "Ctrl+X"))
            {
                // Handle cut
            }
            if (ImGui::MenuItem("Copy", "Ctrl+C"))
            {
                // Handle copy
            }
            if (ImGui::MenuItem("Paste", "Ctrl+V"))
            {
                // Handle paste
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Select All", "Ctrl+A"))
            {
                // Handle select all
            }
            ImGui::EndMenu();
        }
    }

    const char* GetMenuName() const override { return "Edit"; }
    int GetMenuPriority() const override { return 20; }
};

// Example 3: View Menu Provider
class ViewMenuProvider : public IMenuProvider
{
public:
    void RenderMenu() override
    {
        if (ImGui::BeginMenu("View"))
        {
            ImGui::Separator();
            if (ImGui::BeginMenu("Layout"))
            {
                if (ImGui::MenuItem("Default Layout"))
                {
                    // Reset to default layout
                }
                if (ImGui::MenuItem("Coding Layout"))
                {
                    // Switch to coding layout
                }
                if (ImGui::MenuItem("Art Layout"))
                {
                    // Switch to art layout
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
    }

    const char* GetMenuName() const override { return "View"; }
    int GetMenuPriority() const override { return 30; }
};

// Example 4: Tools Menu Provider
class ToolsMenuProvider : public IMenuProvider
{
public:
    void RenderMenu() override
    {
        if (ImGui::BeginMenu("Tools"))
        {
            if (ImGui::MenuItem("Build", "F7"))
            {
                // Handle build
            }
            if (ImGui::MenuItem("Run", "F5"))
            {
                // Handle run
            }
            ImGui::Separator();
            if (ImGui::MenuItem("Preferences", "Ctrl+,"))
            {
                // Handle preferences
            }
            if (ImGui::MenuItem("Plugin Manager"))
            {
                // Handle plugin manager
            }
            ImGui::Separator();
            if (ImGui::BeginMenu("Debug"))
            {
                if (ImGui::MenuItem("Start Debugging", "F9"))
                {
                    // Handle start debug
                }
                if (ImGui::MenuItem("Stop Debugging", "Shift+F5"))
                {
                    // Handle stop debug
                }
                ImGui::EndMenu();
            }
            ImGui::EndMenu();
        }
    }

    const char* GetMenuName() const override { return "Tools"; }
    int GetMenuPriority() const override { return 40; }
};

// Example 1: System Info Status Provider
class SystemInfoStatusProvider : public IStatusProvider
{
private:
    float m_cpuUsage     = 0.0f;
    size_t m_memoryUsage = 0;
    size_t m_totalMemory = 0;

    void UpdateSystemInfo()
    {
        // Implementation similar to the original system info code
        static auto lastUpdate = std::chrono::steady_clock::now();
        auto now               = std::chrono::steady_clock::now();

        if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastUpdate).count() > 1000)
        {
            lastUpdate = now;
            // Update system info here
        }
    }

public:
    void RenderStatus() override
    {
        UpdateSystemInfo();
        ImGui::Text("CPU: %.1f%%", m_cpuUsage);
        ImGui::SameLine();
        ImGui::Text("Memory: %zu/%zu MB", m_memoryUsage, m_totalMemory);
    }

    int GetStatusPriority() const override { return 10; }
};

// Example 2: Project Status Provider
class ProjectStatusProvider : public IStatusProvider
{
private:
    std::string m_projectName = "MyProject";
    std::string m_currentFile = "main.cpp";
    bool m_hasUnsavedChanges  = false;

public:
    void RenderStatus() override
    {
        ImGui::Text("Project: %s", m_projectName.c_str());
        ImGui::SameLine();
        ImGui::Text("File: %s%s", m_currentFile.c_str(), m_hasUnsavedChanges ? "*" : "");
    }

    int GetStatusPriority() const override { return 20; }

    void SetCurrentFile(const std::string& filename, bool unsaved = false)
    {
        m_currentFile       = filename;
        m_hasUnsavedChanges = unsaved;
    }
};

// Example 3: Build Status Provider
class BuildStatusProvider : public IStatusProvider
{
private:
    enum class BuildState
    {
        Idle,
        Building,
        Success,
        Failed
    };
    BuildState m_buildState    = BuildState::Idle;
    std::string m_buildMessage = "Ready";
    int m_errorCount           = 0;
    int m_warningCount         = 0;

public:
    void RenderStatus() override
    {
        ImVec4 color = ImVec4(1, 1, 1, 1);

        switch (m_buildState)
        {
        case BuildState::Building:
            color = ImVec4(1, 1, 0, 1); // Yellow
            break;
        case BuildState::Success:
            color = ImVec4(0, 1, 0, 1); // Green
            break;
        case BuildState::Failed:
            color = ImVec4(1, 0, 0, 1); // Red
            break;
        }

        ImGui::PushStyleColor(ImGuiCol_Text, color);
        ImGui::Text("Build: %s", m_buildMessage.c_str());
        ImGui::PopStyleColor();

        if (m_errorCount > 0 || m_warningCount > 0)
        {
            ImGui::SameLine();
            ImGui::Text("(%d errors, %d warnings)", m_errorCount, m_warningCount);
        }
    }

    int GetStatusPriority() const override { return 30; }

    void SetBuildState(BuildState state, const std::string& message = "", int errors = 0, int warnings = 0)
    {
        m_buildState   = state;
        m_buildMessage = message;
        m_errorCount   = errors;
        m_warningCount = warnings;
    }
};

// Example 4: Clock Status Provider
class ClockStatusProvider : public IStatusProvider
{
public:
    void RenderStatus() override
    {
        auto now    = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        auto tm     = *std::localtime(&time_t);

        ImGui::Text("%.2d:%.2d:%.2d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    }

    int GetStatusPriority() const override { return 1000; } // Far right
};

} // namespace Ren::Editor
