#include <typeinfo>
#include "Rengine/Core/MainApplication.hpp"
#include "Rengine/Core/StateMachine.hpp"
#include "Rengine/Core/AssetManager.hpp"

ren::MainApplication::MainApplication(ren::ApplicationProperties app_properties)
{
	_window.create(app_properties.settings.video_mode, 
		app_properties.name, 
		app_properties.settings.fullscreen ? sf::Style::Fullscreen : sf::Style::Close);
	_window.setFramerateLimit(app_properties.settings.framerate_limit);

	_environment = std::make_shared<Environment>();

	_environment->GetAssetManager()->loadGlobalAssets();
}


ren::MainApplication::~MainApplication()
{
	_environment->Dispose();
}

void ren::MainApplication::Run(State* firstState)
{
	_environment->GetStateMachine()->ChangeState(firstState);
	TimeKeeper::InitializeTime();
	
	while (_window.isOpen())
	{
		TimeKeeper::UpdateTime();

		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) _window.close();
			_environment->GetStateMachine()->GetActiveState()->EventHandler(event, _window);
			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Tilde)
					Debug::log("OpenConsole");
		}

		_environment->GetStateMachine()->GetActiveState()->Update(TimeKeeper::DeltaTime());

		_window.clear();
		_environment->GetStateMachine()->GetActiveState()->Render(_window);
	
		_window.display();
	}
}

void ren::MainApplication::CloseApplication()
{
	_window.close();
}
