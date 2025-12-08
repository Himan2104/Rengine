#pragma once

#include "Rengine/Core/EventSystem.hxx"
#include <Rengine/Core/Definitions.hxx>
#include <memory>
#include <string_view>

namespace Ren::Input::Devices
{

class IDevice
{
public:
    virtual ~IDevice()                       = default;
    virtual UInt32 GetDeviceID() const       = 0;
    virtual std::string_view GetDeviceName() = 0;
};

class OnDeviceConnected : Ren::IEvent
{
    std::weak_ptr<IDevice> connectedDevice;
    std::string_view deviceName;
    UInt32 deviceID;
};

class OnDeviceDisconnected : Ren::IEvent
{
    std::weak_ptr<IDevice> connectedDevice;
    std::string_view deviceName;
    UInt32 deviceID;
};

} // namespace Ren::Input::Devices
