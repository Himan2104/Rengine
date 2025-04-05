#include "Rengine/Application/IApplication.hpp"
#include "Rengine/Application/Window.hpp"
#include "Rengine/Core/EventSystem.hpp"
#include <GameApplication.hpp>

namespace Ren
{
GameApplication::GameApplication(int argc, char* argv[])
    : IApplication(argc, argv)
{
    _window = new Window(Resolution{1920, 1080}, 32, GetProperties().name, WindowMode::Windowed);
}

Window* GameApplication::GetWindow() { return _window; }

void GameApplication::Close(Int32 exitCode)
{
    _isRunning = false;
    _exitCode  = exitCode;
}

void GameApplication::Initialize()
{
    Ren::EventSystem::GetInstance().Subscribe<WindowEvents::Closed>([&](auto event) { this->Close(); });
}

void GameApplication::Run()
{
    _isRunning = true;
    while (_isRunning) // mainloop
    {
        _window->PollEvents();
    }
}

Int32 GameApplication::Cleanup()
{
    _window->Close();
    delete _window;
    return _exitCode;
}

} // namespace Ren
