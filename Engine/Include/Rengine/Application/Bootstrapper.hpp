#pragma once

#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/Window.hpp"
#include <Rengine/Application/IApplication.hpp>
#include <Rengine/Application/Parameters.hpp>
#include <type_traits>

namespace Ren
{
namespace Application
{

    template <typename T>
    concept IsApplication = std::is_base_of_v<IApplication, T>;

    class Bootstrapper
    {
    public:
        template <IsApplication T> static int Initialize(int argc, char* argv[])
        {
            _params      = new Parameters(argc, argv);
            _application = new T();
            sf::Window window;
            window.create(sf::VideoMode::getFullscreenModes()[0], "rengine");
        }
        friend const IApplication* const GetApplication();
        friend const Parameters* const GetParams();

    private:
        static IApplication* _application;
        static Parameters* _params;
    };

} // namespace Application
} // namespace Ren
