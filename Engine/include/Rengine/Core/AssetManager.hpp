#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Rengine/Config.hpp"

namespace ren
{
	class REN_API AssetManager : public sf::NonCopyable
	{
	public:
		AssetManager();
		~AssetManager();

		static AssetManager* access();

		void loadGlobalAssets();

		void loadTexture(std::string name, std::string filepath);
		void loadFont(std::string name, std::string filepath);
		void loadSFX(std::string name, std::string filepath);
		void loadMusic(std::string name, std::string filepath);



		sf::Texture& getTexture(std::string name);
		sf::Font& getFont(std::string name);
		sf::SoundBuffer& getSFX(std::string name);
		std::string& getMusic(std::string name);

		
	private:
		std::map<std::string, sf::Texture> textures;
		std::map<std::string, sf::Font> fonts;
		std::map<std::string, sf::SoundBuffer> sfx;
		std::map<std::string, std::string> music;

	};
}