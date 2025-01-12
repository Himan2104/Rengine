#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <Rengine/Utility/Debug.hpp>
#include <Rengine/Utility/TimeKeeper.hpp>
#include <Rengine/Config.hpp>

namespace Ren
{
	class Level;
	class Environment;
	struct Settings
	{
		sf::VideoMode video_mode;
		int framerate_limit{};
		bool fullscreen{};
		bool vsync{};
		bool postprocessing{};
	};

	struct ApplicationProperties
	{
		std::string name{};
		uint8_t version_major{};
		uint8_t version_minor{};
		uint8_t version_patch{};
		Settings settings;

        [[nodiscard]] std::string GetVersionString() const
        {
            return std::to_string(version_major) + "." + std::to_string(version_minor) + "." + std::to_string(version_patch);
        }
	};

	class Application
	{
	public:
		explicit Application(Ren::ApplicationProperties app_properties);
		~Application();

		/// <summary>
		/// Tick Application from firstState (arg)
		/// </summary>
		/// <param name="firstState">First state to init the state machine with</param>
		void Run(Level* firstState);

        std::shared_ptr<Environment> GetEnvironment() const
        {
            return _environment;
        }

		void CloseApplication(int exitCode = 0);

	private:
        bool _isRunning = true;
		ApplicationProperties _properties;
		sf::RenderWindow _window;
		std::shared_ptr<Environment> _environment;
        sf::Font _font;
        sf::Text _debugText;
	};

	
	
}
