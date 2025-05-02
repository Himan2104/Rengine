#pragma once

#include <Rengine/Input/Devices/IDevice.hxx>
#include <memory>
#include <vector>

namespace Ren::Input
{

class InputManager
{
private:
    std::vector<std::shared_ptr<Devices::IDevice>> _devices;
};

} // namespace Ren::Input
