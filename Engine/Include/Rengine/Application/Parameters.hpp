#pragma once

#include <map>
#include <string>

namespace Ren
{
namespace Application
{
    class Parameters
    {
    public:
        bool Contains(const std::string& query) const { return _params.contains(query); }
        const std::string& GetAdditionalArguments(const std::string& query) const { return _params.at(query); }

    private:
        Parameters(int argc, char* argv[]);

        std::map<std::string, std::string> _params;

        friend class Bootstrapper;
    };
} // namespace Application
} // namespace Ren
