#include<Rengine/core/MainApplication.hpp>
#include<Rengine/Utility/Misc.hpp>
#include"TestState.hpp"

int main()
{
	ren::Settings stgns
	{
		sf::VideoMode(1920,1080,32), //videomode
		144, //framerate limit
		false, //fullscreen
		false //vsync
	};
	
	ren::ApplicationProperties rop
	{
		"Rengine Demo", //App name
		stgns
	};
	ren::MainApplication* Application = new ren::MainApplication(rop);

	Application->run(new TestState(Application->environment()));

	delete Application;
	return 0;
}
