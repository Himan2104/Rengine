#pragma once
#include<SFML/Graphics.hpp>
#include"Rengine/Utility/Debug.hpp"
#include"Rengine/Core/AssetManager.hpp"
#include"Rengine/Utility/TimeKeeper.hpp"
#include"Rengine/Config.hpp"
#include"Rengine/Core/State.hpp"


namespace ren
{
	struct REN_API Settings
	{
		sf::VideoMode video_mode;
		int framerate_limit{};
		bool fullscreen{};
		bool vsync{};
	};

	struct REN_API ApplicationProperties
	{
		std::string name;
		Settings settings;
	};

	class REN_API MainApplication
	{
	public:
		MainApplication(ren::ApplicationProperties app_properties);
		~MainApplication();

		/// <summary>
		/// Start Application from firstState (arg)
		/// </summary>
		/// <param name="firstState">First state to init the state machine with</param>
		void run(State* firstState);

		void closeApplication();

	private:
		sf::VideoMode video_mode;
		sf::RenderWindow window;
	};

	
	
}
