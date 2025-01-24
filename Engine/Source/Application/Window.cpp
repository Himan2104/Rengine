#include <Rengine/Application/Window.hpp>

namespace Ren
{
namespace Application
{
    constexpr Window::Window(uint16_t width, uint16_t height, uint8_t colorDepth, const std::string& title)
        : _width(width)
        , _height(height)
        , _colorDepth(colorDepth)
        , _title(title)
    {
    }
} // namespace Application
} // namespace Ren
