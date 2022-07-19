#pragma once
#include<SFML/Graphics.hpp>
#include"Rengine/Utility/Debug.hpp"
#include"Rengine/Core/Environment.hpp"
#include"Rengine/Utility/TimeKeeper.hpp"
#include"Rengine/Config.hpp"



namespace ren
{
	
	class REN_API State;
	
	struct REN_API Settings
	{
		sf::VideoMode video_mode;
		int framerate_limit{};
		bool fullscreen{};
		bool vsync{};
		bool postprocessing{};
		bool debug_mode{};
		bool show_fps{};
		bool show_debug_info{};
	};

	struct REN_API ApplicationProperties
	{
		std::string name;
		uint32_t version_major;
		uint32_t version_minor;
		uint32_t version_patch;
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

		/// <summary>
		/// Get the global api environment 
		/// </summary>
		/// <returns>weak pointer to current application instance's environment</returns>
		std::weak_ptr<Environment> gEnv; 

		void closeApplication();

	private:
		sf::VideoMode _video_mode;
		sf::RenderWindow _window;
		std::shared_ptr<Environment> _environment;
	};

	
	
}
