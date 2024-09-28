
#include "Rengine/core/AssetManager.hpp"
#include<iostream>

ren::AssetManager::AssetManager()
{
}

ren::AssetManager::~AssetManager()
{
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

void ren::AssetManager::loadTexture(std::string_view name, std::string filepath)
{
	sf::Texture temp;
	if (!temp.loadFromFile(filepath)) std::cout << name << " failed to load" << std::endl;
	else _textures.insert(std::make_pair(name, temp));
}

void ren::AssetManager::loadFont(std::string_view name, std::string filepath)
{
	sf::Font temp;
	if (!temp.loadFromFile(filepath)) std::cout << name << " failed to load" << std::endl;
	else _fonts.insert(std::make_pair(name, temp));
}

void ren::AssetManager::loadSFX(std::string_view name, std::string filepath)
{
	sf::SoundBuffer temp;
	if (!temp.loadFromFile(filepath)) std::cout << name << " failed to load" << std::endl;
	else _sfx.insert(std::make_pair(name, temp));
}

void ren::AssetManager::loadMusic(std::string_view name, std::string filepath)
{
	_music.insert(std::make_pair(name, filepath));
}



sf::Texture& ren::AssetManager::getTexture(std::string_view name)
{
	if (_textures.count(name.data())) return _textures.at(name.data());
	else return _textures.at("texture_not_found");
}

sf::Font& ren::AssetManager::getFont(std::string_view name)
{
	if (_fonts.count(name.data())) return _fonts.at(name.data());
	else return _fonts.at("default_font");
}

sf::SoundBuffer& ren::AssetManager::getSFX(std::string_view name)
{
	if (_sfx.count(name.data())) return _sfx.at(name.data());
	else return _sfx.at("sfx_not_found");
}

std::string& ren::AssetManager::getMusic(std::string_view name)
{
	if (_music.count(name.data())) return _music.at(name.data());
	else return _music.at("music_not_found");
}


