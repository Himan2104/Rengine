#include <GameApplication.hxx>
#include <Rengine/Application/Bootstrapper.hxx>

int main(int argc, char* argv[]) { return Ren::Bootstrapper::Initialize<Ren::GameApplication>(argc, argv); }
