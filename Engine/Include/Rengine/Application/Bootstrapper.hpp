#pragma once

#include "Rengine/Core/Log.hpp"
#include <Rengine/Application/IApplication.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Window.hpp>
#include <type_traits>

namespace Ren
{
template <typename T>
concept IsApplication = std::is_base_of_v<IApplication, T>;

class Bootstrapper
{
public:
    template <IsApplication T> static int Initialize(int argc, char* argv[])
    {
        _application = new T(argc, argv);
        _application->Initialize();
        REN_LOG_INFO("Application Initialized");
        _application->Run();
        REN_LOG_INFO("Finished main loop.... Creating cache cleanup cycle and exiting.");
        return _application->Cleanup();
    }
    friend IApplication* const GetApplication();

private:
    static IApplication* _application;
};

} // namespace Ren
