#pragma once

#include "SFML/Window/Keyboard.hpp"
#include <Rengine/Core/Types.hxx>
#include <Rengine/Input/Devices/IDevice.hxx>

namespace Ren::Input::Devices
{

class Keyboard : IDevice
{
public:
    Keyboard();
    ~Keyboard() {}

    [[nodiscard]] bool IsKeyPressed();

private:
    UInt32 _deviceID;
};

} // namespace Ren::Input::Devices
