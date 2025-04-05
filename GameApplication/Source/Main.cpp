#include <GameApplication.hpp>
#include <Rengine/Application/Bootstrapper.hpp>

int main(int argc, char* argv[]) { return Ren::Bootstrapper::Initialize<Ren::GameApplication>(argc, argv); }
