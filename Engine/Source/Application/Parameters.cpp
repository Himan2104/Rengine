#include <Rengine/Application/Parameters.hpp>
#include <sstream>

namespace Ren
{
namespace Application
{

    Parameters::Parameters(int argc, char* argv[])
    {
        for (int i = 1; i < argc; i++)
        {
            std::string arg = argv[i];
            if (arg[0] == '-')
            {
                std::string key = arg;
                std::stringstream values;
                while (i + 1 < argc && argv[i + 1][0] != '-')
                {
                    ++i;
                    std::string value = argv[i];
                    if (value[0] == '"')
                    {
                        value = value.substr(1);
                        while (i + 1 < argc && argv[i + 1][strlen(argv[i + 1]) - 1] != '"')
                        {
                            value += " " + std::string(argv[++i]);
                        }
                        value += " " + std::string(argv[++i]).substr(0, strlen(argv[i]) - 1);
                    }
                    if (!values.str().empty()) { values << " "; }
                    values << value;
                }
            }
        }
    }
} // namespace Application
} // namespace Ren
