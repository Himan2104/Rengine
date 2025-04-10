#pragma once

#include "SFML/Window/Keyboard.hpp"
#include <Rengine/Core/Definitions.hpp>
#include <Rengine/Input/Devices/IDevice.hpp>

namespace Ren::Input::Devices
{

class Keyboard : IDevice
{
public:
using Key = sf::Keyboard::Key

    public : Keyboard();
    virtual void ~Keyboard();

    [[nodiscard]] bool IsKeyPressed();

private:
    UInt32 _deviceID;
};

} // namespace Ren::Input::Devices
