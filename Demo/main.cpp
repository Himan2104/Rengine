#include<Rengine/core/MainApplication.hpp>
#include<Rengine/Utility/Misc.hpp>
#include"TestState.hpp"

int main()
{
	ren::MainApplication *Application = new ren::MainApplication(sf::VideoMode(1920,1080), "Rengine Demo");

	Application->run(new TestState());

	delete Application;
	return 0;
}