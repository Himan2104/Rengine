#include "SFML/Window/VideoMode.hpp"
#include <Rengine/Application/Resolution.hpp>

namespace Ren
{
const std::vector<Resolution>& Resolution::GetAvailableResolutions()
{
    static const auto res = []
    {
        std::vector<Resolution> result;
        for (sf::VideoMode vm : sf::VideoMode::getFullscreenModes()) { result.push_back(Resolution(vm.size.x, vm.size.y)); }
        return result;
    }();

    return res;
}
} // namespace Ren
