#include <typeinfo>
#include "Rengine/core/MainApplication.hpp"
#include "Rengine/core/StateMachine.hpp"

ren::MainApplication::MainApplication(sf::VideoMode Vmode, std::string name)
{
	this->Vmode = Vmode;
	window.create(this->Vmode, name, sf::Style::Close);
	window.setFramerateLimit(0);
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
