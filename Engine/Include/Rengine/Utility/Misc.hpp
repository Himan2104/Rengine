#pragma once
#include"Rengine/Config.hpp"
#include<string>

namespace Ren
{
    

    /// <summary>
    /// Get the current date and time as a string
    /// </summary>
    /// <param name="format"> Format string, default is [YYYY-MM-DD|HH:MM:SS]</param>
    /// <returns>String of current date and time as the specified format</returns>
    std::string GetCurrentTime(const char* format = "[%Y-%m-%d|%X]");
    

    //TODO: Get rid of the template. Very unsafe. Using this approach since
    //getGlobalBounds is defined differently in sf::Shape and sf::Sprite separately.
    //This will however be fixed inevitably when I create my own ECS for handling 
    //in-game objects or as it states Entities :)

    /// <summary>
    /// Set the origin/pivot of the object to the center
    /// </summary>
    /// <typeparam name="T">Shape or Sprite</typeparam>
    /// <param name="object">Object with shape/sprite</param>
    template<typename T>
    inline void CenterOrigin(T& object)
    {
        object.setOrigin(object.getGlobalBounds().getCenter());
    }

    /// <summary>
    /// Encrypts a given string
    /// </summary>
    void Encrypt(std::string& str);

    /// <summary>
    /// Decrypt a string which was encrypted by Ren::Encrypt()
    /// </summary>
    void Decrypt(std::string& str);

    /// <summary>
    /// Returns the current engine verision as a string
    /// </summary>
    /// <returns>std::string</returns>
    inline std::string GetEngineVersion()
    {
        return std::string(std::to_string(REN_VERSION_MAJOR) + "." + std::to_string(REN_VERSION_MINOR) + "." + std::to_string(REN_VERSION_PATCH));
    }
}
