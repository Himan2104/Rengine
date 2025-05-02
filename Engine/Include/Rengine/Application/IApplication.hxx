#pragma once

#include <Rengine/Config.hxx>
#include <Rengine/Core/Definitions.hxx>
#include <Rengine/Core/Version.hxx>
#include <cstring>
#include <map>
#include <sstream>
#include <string>

#ifndef REN_APPLICATION_NAME
    #define REN_APPLICATION_NAME "Rengine"
#endif

namespace Ren
{
struct ApplicationProperties
{
    std::string name{};
    Version version{};
};

class ApplicationParameters final
{
public:
    bool Contains(const std::string& query) const { return _params.contains(query); }
    const std::string& GetAdditionalArguments(const std::string& query) const { return _params.at(query); }

private:
    ApplicationParameters(int argc, char* argv[])
    {
        for (int i = 1; i < argc; i++)
        {
            std::string arg = argv[i];
            if (arg[0] == '-')
            {
                std::string key = arg;
                std::stringstream values{};
                while (i + 1 < argc && argv[i + 1][0] != '-')
                {
                    ++i;
                    std::string value = argv[i];
                    if (value[0] == '"')
                    {
                        value = value.substr(1);
                        while (i + 1 < argc && argv[i + 1][strlen(argv[i + 1]) - 1] != '"') { value += " " + std::string(argv[++i]); }
                        value += " " + std::string(argv[++i]).substr(0, strlen(argv[i]) - 1);
                    }
                    if (!values.str().empty()) { values << " "; }
                    values << value;
                }
            }
        }
    }

    std::map<std::string, std::string> _params;

    friend class IApplication;
};

class IApplication
{
public:
    const ApplicationParameters& GetParameters() const { return _parameters; }
    const ApplicationProperties& GetProperties() const { return _properties; }

    virtual class Window* GetWindow() = 0;

    virtual void Close(Int32 exitCode) = 0;
    virtual bool IsRunning() const     = 0;

private:
    IApplication()               = delete;
    IApplication(IApplication&)  = delete;
    IApplication(IApplication&&) = delete;

protected:
    IApplication(int argc, char* argv[])
        : _parameters(argc, argv)
    {
        _properties.name    = REN_APPLICATION_NAME;
        _properties.version = {REN_VERSION_MAJOR, REN_VERSION_MINOR, REN_VERSION_PATCH};
    }
    virtual void Initialize() = 0;
    virtual void Run()        = 0;
    virtual Int32 Cleanup()   = 0;

private:
    ApplicationParameters _parameters;
    ApplicationProperties _properties;
    friend class Bootstrapper;
};
} // namespace Ren
