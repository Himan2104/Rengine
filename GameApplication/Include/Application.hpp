#pragma once

#include <Rengine/Application/IApplication.hpp>
#include <memory>
#include <string>

namespace Ren
{
class Level;
class Environment;
struct ApplicationProperties
{
    std::string name{};
    uint8_t version_major{};
    uint8_t version_minor{};
    uint8_t version_patch{};

    [[nodiscard]] std::string GetVersionString() const
    {
        return std::to_string(version_major) + "." + std::to_string(version_minor) + "." +
            std::to_string(version_patch);
    }
};

class Application : public IApplication
{
public:
    constexpr Application();

    void Run(Level* firstState);

    void CloseApplication(int exitCode = 0);

private:
    bool _isRunning = true;
    ApplicationProperties _properties;
};

} // namespace Ren
