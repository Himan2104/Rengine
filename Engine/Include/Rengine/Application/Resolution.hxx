#pragma once

#include <cstdint>
#include <vector>

namespace Ren
{
class Resolution
{
public:
    constexpr Resolution(uint16_t width, uint16_t height)
        : _width{width}
        , _height{height}
    {
    }

    uint16_t GetWidth() const { return _width; }
    uint16_t GetHeight() const { return _height; }

    static const std::vector<Resolution>& GetAvailableResolutions();

private:
    uint16_t _width;
    uint16_t _height;
};
} // namespace Ren
