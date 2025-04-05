#include <Rengine/Application/Bootstrapper.hpp>
#include <Rengine/Application/IApplication.hpp>

namespace Ren
{

IApplication* Bootstrapper::_application = nullptr;

IApplication* const GetApplication() { return Bootstrapper::_application; }
} // namespace Ren
