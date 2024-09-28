#include<Rengine/core/Application.hpp>
#include<Rengine/Utility/Misc.hpp>
#include"TestState.hpp"

int main()
{
    ren::Settings _settings
    {
        sf::VideoMode(1920,1080,32), //videomode
        144, //framerate limit
        false, //fullscreen
        false //vsync
    };

    ren::ApplicationProperties _application_properties
    {
        "Rengine Demo", //App name
        0u, 1u, 1u, _settings
    };
    auto* _application = new ren::Application(_application_properties);

    _application->Run(new TestState(_application->GetEnvironment()));

    delete _application;
    return 0;
}
