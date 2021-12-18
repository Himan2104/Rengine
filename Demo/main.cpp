#include<Rengine/core/MainApplication.hpp>
#include<Rengine/Utility/Misc.hpp>
#include"TestState.hpp"

int main()
{
	ren::Settings stgns{
		sf::VideoMode(1920,1080,64), //videomode
				144, //framerate limit
				true, //fullscreen
				false //vsync
	};
	ren::ApplicationProperties rop{
			"Rengine Demo", //App name
			stgns
	};
	ren::MainApplication* Application = new ren::MainApplication(&rop);

	Application->run(new TestState());

	delete Application;
	return 0;
}