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
		MainApplication(sf::VideoMode videomode, std::string name = "NewWindow");
		~MainApplication();

		void run(State* firstState);

		void closeApplication();

	private:
		sf::VideoMode video_mode;
		sf::RenderWindow window;
	};
}
