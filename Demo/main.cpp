#include<Rengine/core/MainApplication.hpp>
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
	ren::MainApplication* _application = new ren::MainApplication(_application_properties);

	_application->Run(new TestState(_application->gEnv));

	delete _application;
	return 0;
}
