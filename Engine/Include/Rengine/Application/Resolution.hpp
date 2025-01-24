#pragma once

#include <cstdint>
#include <vector>

namespace Ren
{
namespace Application
{
    class Resolution
    {
    public:
        constexpr Resolution(uint16_t width, uint16_t height);
        ~Resolution();

        static const std::vector<Resolution>& GetAvailableResolutions();

    private:
        uint16_t _width;
        uint16_t _height;
    };
} // namespace Application
} // namespace Ren
