#include "Rengine/Application/IApplication.hpp"
#include "Rengine/Application/Parameters.hpp"
#include <Rengine/Application/Bootstrapper.hpp>

namespace Ren
{
namespace Application
{

    IApplication* Bootstrapper::_application = nullptr;
    Parameters* Bootstrapper::_params        = nullptr;

    const IApplication* const GetApplication() { return Bootstrapper::_application; }
    const Parameters* const GetParams() { return Bootstrapper::_params; }

} // namespace Application
} // namespace Ren
