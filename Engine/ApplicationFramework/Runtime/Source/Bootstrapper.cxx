#include <Rengine/Application/Bootstrapper.hxx>
#include <Rengine/Application/IApplication.hxx>

namespace Ren
{

IApplication* Bootstrapper::_application = nullptr;

IApplication* const GetApplication() { return Bootstrapper::_application; }
} // namespace Ren
