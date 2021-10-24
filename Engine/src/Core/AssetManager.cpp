
#include "Rengine/core/AssetManager.hpp"
#include<iostream>

ren::AssetManager::AssetManager()
{
}

ren::AssetManager::~AssetManager()
{
}

ren::AssetManager* ren::AssetManager::access()
{
	static AssetManager assMan;
	return &assMan;
}

void ren::AssetManager::loadGlobalAssets()
{
	//fonts
	loadFont("default_font", "data/fonts/neuropol.ttf");
	loadFont("con_font", "data/fonts/consola.ttf");

	//textures
	loadTexture("texture_not_found", "data/images/NAtex.png");
	loadTexture("rgs_logo", "data/images/goat.png");
	loadTexture("mm_title", "data/images/Title.png");
	loadTexture("testSprite", "data/images/testSprite.png");
	loadTexture("spsc_banner", "data/images/banner.png");
	loadTexture("spsc_creds", "data/images/creds.png");
	loadTexture("lightning", "data/images/lightning.png");
	loadTexture("mm_bg", "data/images/mainmenubg.png");
	loadTexture("mm_h1", "data/images/h1.png");

	//sfx
	loadSFX("sfx_not_found", "data/audio/sfx/NAsfx.wav");

	//music
	loadMusic("music_not_found", "data/audio/music/NAmusic.ogg");
	loadMusic("tresh", "data/audio/music/Tresh.ogg");
	
}

void ren::AssetManager::loadTexture(std::string name, std::string filepath)
{
	sf::Texture temp;
	if (!temp.loadFromFile(filepath)) std::cout << name + " failed to load" << std::endl;
	else textures.insert(std::make_pair(name, temp));
}

void ren::AssetManager::loadFont(std::string name, std::string filepath)
{
	sf::Font temp;
	if (!temp.loadFromFile(filepath)) std::cout << name + " failed to load" << std::endl;
	else fonts.insert(std::make_pair(name, temp));
}

void ren::AssetManager::loadSFX(std::string name, std::string filepath)
{
	sf::SoundBuffer temp;
	if (!temp.loadFromFile(filepath)) std::cout << name + " failed to load" << std::endl;
	else sfx.insert(std::make_pair(name, temp));
}

void ren::AssetManager::loadMusic(std::string name, std::string filepath)
{
	music.insert(std::make_pair(name, filepath));
}



sf::Texture& ren::AssetManager::getTexture(std::string name)
{
	if (textures.count(name)) return textures.at(name);
	else return textures.at("texture_not_found");
}

sf::Font& ren::AssetManager::getFont(std::string name)
{
	if (fonts.count(name)) return fonts.at(name);
	else return fonts.at("default_font");
}

sf::SoundBuffer& ren::AssetManager::getSFX(std::string name)
{
	if (sfx.count(name)) return sfx.at(name);
	else return sfx.at("sfx_not_found");
}

std::string& ren::AssetManager::getMusic(std::string name)
{
	if (music.count(name)) return music.at(name);
	else return music.at("music_not_found");
}


