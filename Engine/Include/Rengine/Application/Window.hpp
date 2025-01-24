#pragma once

#include "SFML/Window/Window.hpp"
#include <cstdint>
#include <string>
namespace Ren
{
namespace Application
{
    class Window
    {
    public:
        constexpr Window(uint16_t width, uint16_t height, uint8_t colorDepth, const std::string& title);
        ~Window();

        void Close();
        void SetResolution(uint16_t width, uint16_t);

    private:
        sf::Window* _window = nullptr;

        uint16_t _width;
        uint16_t _height;
        uint8_t _colorDepth;
        std::string _title;
    };
} // namespace Application
} // namespace Ren
