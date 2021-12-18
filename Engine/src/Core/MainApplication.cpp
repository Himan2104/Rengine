#include <typeinfo>
#include "Rengine/Core/MainApplication.hpp"
#include "Rengine/Core/StateMachine.hpp"

ren::MainApplication::MainApplication(ren::ApplicationProperties app_properties)
{
	window.create(app_properties.settings.video_mode, 
		app_properties.name, 
		app_properties.settings.fullscreen ? sf::Style::Fullscreen : sf::Style::Close);
	window.setFramerateLimit(app_properties.settings.framerate_limit);
	//AssetManager::access()->loadGlobalAssets();
}



ren::MainApplication::~MainApplication()
{
}

void ren::MainApplication::run(State* firstState)
{
	StateMachine::access()->changeState(firstState);
	TimeKeeper::initializeTime();

	while (window.isOpen())
	{
		TimeKeeper::updateTime();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			StateMachine::access()->getActiveState()->eventHandler(event, window);
		}

		StateMachine::access()->getActiveState()->update(TimeKeeper::deltaTime());

		window.clear();
		StateMachine::access()->getActiveState()->draw(window);
	
		window.display();
	}
}

void ren::MainApplication::closeApplication()
{
	window.close();
}
