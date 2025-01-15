#pragma once
#include "Rengine/Config.hpp"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <map>

namespace Ren
{
class AssetManager
{
public:
    AssetManager();
    ~AssetManager();

    void loadGlobalAssets();

    void loadTexture(std::string_view name, std::string filepath);
    void loadFont(std::string_view name, std::string filepath);
    void loadSFX(std::string_view name, std::string filepath);
    void loadMusic(std::string_view name, std::string filepath);

    sf::Texture& getTexture(std::string_view name);
    sf::Font& getFont(std::string_view name);
    sf::SoundBuffer& getSFX(std::string_view name);
    std::string& getMusic(std::string_view name);

private:
    std::map<std::string, sf::Texture> _textures;
    std::map<std::string, sf::Font> _fonts;
    std::map<std::string, sf::SoundBuffer> _sfx;
    std::map<std::string, std::string> _music;
};
} // namespace Ren
