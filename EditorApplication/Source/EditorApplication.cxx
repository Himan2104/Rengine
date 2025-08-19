#include <DemoArtifacts.hxx>
#include <EditorApplication.hxx>
#include <Rengine/Editor/MainEditorUI.hxx>
#include <SFML/Graphics/RenderWindow.hpp>
#include <imgui-SFML.h>
#include <imgui.h>

namespace Ren
{
EditorApplication::EditorApplication(int argc, char* argv[])
    : IApplication(argc, argv)
{
    _window = new Window(Resolution{1920, 1080}, 32, GetProperties().name, WindowMode::Windowed);
}

Window* EditorApplication::GetWindow() { return _window; }

void EditorApplication::Close(Int32 exitCode)
{
    _isRunning = false;
    _exitCode  = exitCode;
}

void EditorApplication::Initialize()
{
    Ren::EventSystem::GetInstance().Subscribe<WindowEvents::Closed>([&](auto event) { this->Close(); });
}

void EditorApplication::Run()
{
    Editor::MainEditorUI editor;

    editor.AddWindow(std::make_unique<Editor::PropertiesWindow>());
    editor.AddWindow(std::make_unique<Editor::EntitiesWindow>());
    editor.AddWindow(std::make_unique<Editor::ConsoleWindow>());

    // Add menu providers
    editor.AddMenuProvider(std::make_unique<Editor::FileMenuProvider>());
    editor.AddMenuProvider(std::make_unique<Editor::EditMenuProvider>());
    editor.AddMenuProvider(std::make_unique<Editor::ViewMenuProvider>());
    editor.AddMenuProvider(std::make_unique<Editor::ToolsMenuProvider>());

    // Add status providers
    editor.AddStatusProvider(std::make_unique<Editor::SystemInfoStatusProvider>());
    editor.AddStatusProvider(std::make_unique<Editor::ProjectStatusProvider>());
    editor.AddStatusProvider(std::make_unique<Editor::BuildStatusProvider>());
    editor.AddStatusProvider(std::make_unique<Editor::ClockStatusProvider>());

    _isRunning = true;
    while (_isRunning) // mainloop
    {
        _window->PollEvents();

        _window->Clear();
        editor.RenderFrame();
        _window->Display();
    }
}

Int32 EditorApplication::Cleanup()
{
    _window->Close();
    delete _window;
    return _exitCode;
}

} // namespace Ren
