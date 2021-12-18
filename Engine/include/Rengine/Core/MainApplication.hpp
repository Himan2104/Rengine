#pragma once
#include<SFML/Graphics.hpp>
#include"Rengine/utility/Debug.hpp"
#include"Rengine/core/AssetManager.hpp"
#include"Rengine/utility/TimeKeeper.hpp"
#include"Rengine/Config.hpp"
#include"Rengine/core/State.hpp"


namespace ren
{
	class REN_API MainApplication
	{
	public:
		MainApplication(ApplicationProperties app_properties);
		~MainApplication();

		void run(State* firstState);

		void closeApplication();

	private:
		sf::VideoMode video_mode;
		sf::RenderWindow window;
	};

	struct REN_API Settings
	{
		sf::VideoMode video_mode;
		int framerate_limit;
		bool fullscreen;
		bool vsync;
	};

	struct REN_API ApplicationProperties
	{
		std::string name;
		Settings settings;
	};
}
