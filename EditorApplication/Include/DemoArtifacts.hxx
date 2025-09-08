#pragma once

#include "Rengine/Core/Definitions.hxx"
#include "Rengine/Core/Log.hxx"
#include <Rengine/Editor/EditorWindow.hxx>
#include <Rengine/Editor/MenuProvider.hxx>
#include <Rengine/Editor/StatusProvider.hxx>
#include <chrono>
#include <imgui.h>
#include <string>
#include <vector>

namespace Ren::Editor
{
// Example 1: Properties Window
class PropertiesWindow : public EditorWindow<"Properties", ImGuiWindowFlags_None>
{
private:
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
};

// Example 2: Scene Hierarchy Window
class EntitiesWindow : public EditorWindow<"Entities", ImGuiWindowFlags_None>
{
private:
    std::vector<std::string> _entities = {"Main Camera", "Directional Light", "Player",        "Enemy1",      "Enemy2",
                                          "Terrain",     "UI Canvas",         "Audio Manager", "Game Manager"};
    int _selectedObject                = -1;

public:
    void Render() override
    {
        for (int i = 0; i < _entities.size(); ++i)
        {
            bool isSelected = (_selectedObject == i);
            if (ImGui::Selectable(_entities[i].c_str(), isSelected)) { _selectedObject = i; }

            if (ImGui::BeginPopupContextItem())
            {
                if (ImGui::MenuItem("Delete"))
                {
                    _entities.erase(_entities.begin() + i);
                    _selectedObject = -1;
                }
                if (ImGui::MenuItem("Duplicate")) { _entities.insert(_entities.begin() + i + 1, _entities[i] + " Copy"); }
                ImGui::EndPopup();
            }
        }

        ImGui::Separator();
        if (ImGui::Button("Add GameObject")) { _entities.push_back("New GameObject"); }
    }
};

// Example 3: Console Window
class ConsoleWindow : public EditorWindow<"Console", ImGuiFocusedFlags_None>
{
public:
    class ConsoleLogChannel : public ILogChannel
    {
    public:
        constexpr ConsoleLogChannel(ConsoleWindow* cw)
            : _consoleWindow{cw}
        {
        }

        constexpr void OnLogged(const LogEntry& log) override { _consoleWindow->AddLog(std::format("{}", log)); }

    private:
        ConsoleWindow* _consoleWindow{nullptr};
    };

private:
    std::vector<std::string> _logs;
    char _inputBuffer[256] = "";
    bool _autoScroll       = true;

public:
    constexpr ConsoleWindow() { LogSystem::GetInstance().AddChannel<ConsoleLogChannel>(this); }

    void Render() override
    {
        ImGui::Text("Console");
        ImGui::SameLine();
        if (ImGui::SmallButton("Clear")) { _logs.clear(); }
        ImGui::SameLine();
        ImGui::Checkbox("Auto-scroll", &_autoScroll);

        ImGui::Separator();

        // Log display
        ImGui::BeginChild("ScrollingRegion", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()), false,
                          ImGuiWindowFlags_HorizontalScrollbar);

        for (const auto& log : _logs)
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

        if (_autoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) { ImGui::SetScrollHereY(1.0f); }

        ImGui::EndChild();

        // Command input
        if (ImGui::InputText("Command", _inputBuffer, sizeof(_inputBuffer), ImGuiInputTextFlags_EnterReturnsTrue))
        {
            if (strlen(_inputBuffer) > 0)
            {
                REN_LOG_INFO(_inputBuffer);
                _inputBuffer[0] = '\0';
            }
        }
    }

    constexpr void AddLog(const std::string& log) { _logs.push_back(log); }
};

// Example 1: File Menu Provider
class FileMenuProvider : public MenuProvider<"File", 0>
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
};

// Example 2: Edit Menu Provider
class EditMenuProvider : public MenuProvider<"Edit", 1>
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
};

// Example 3: View Menu Provider
class ViewMenuProvider : public MenuProvider<"View", 4>
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
};

// Example 4: Tools Menu Provider
class ToolsMenuProvider : public MenuProvider<"Tools", 3>
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
};

// Example 1: System Info Status Provider
class SystemInfoStatusProvider : public StatusProvider<"SysInfo", 0>
{
private:
    Float32 _cpuUsage   = 0.0f;
    UInt16 _memoryUsage = 0;
    UInt16 _totalMemory = 0;

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
    void Render() override
    {
        UpdateSystemInfo();
        ImGui::Text("CPU: %.1f%%", _cpuUsage);
        ImGui::SameLine();
        ImGui::Text("Memory: %u/%u MB", _memoryUsage, _totalMemory);
    }

    Float32 GetWidth() const override { return 100.0f; }
};

// Example 2: Project Status Provider
class ProjectStatusProvider : public StatusProvider<"Project", 1>
{
private:
    std::string _projectName = "Rengine";
    bool _hasUnsavedChanges  = false;

public:
    void Render() override { ImGui::Text("Project: %s", (_projectName + (_hasUnsavedChanges ? "*" : "")).c_str()); }
    Float32 GetWidth() const override { return 100.0f; }
};

// Example 3: Build Status Provider
class BuildStatusProvider : public StatusProvider<"BuildStatus", 2>
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
    void Render() override
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

    void SetBuildState(BuildState state, const std::string& message = "", int errors = 0, int warnings = 0)
    {
        m_buildState   = state;
        m_buildMessage = message;
        m_errorCount   = errors;
        m_warningCount = warnings;
    }

    Float32 GetWidth() const override { return 60.0f; }
};

// Example 4: Clock Status Provider
class ClockStatusProvider : public StatusProvider<"Clock", 3>
{
public:
    void Render() override
    {
        auto now    = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        auto tm     = *std::localtime(&time_t);

        ImGui::Text("%.2d:%.2d:%.2d", tm.tm_hour, tm.tm_min, tm.tm_sec);
    }

    Float32 GetWidth() const override { return 60.0f; }
};

} // namespace Ren::Editor
