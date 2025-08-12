#include <EditorApplication.hxx>
#include <Rengine/Application/Bootstrapper.hxx>

int main(int argc, char* argv[]) { return Ren::Bootstrapper::Initialize<Ren::EditorApplication>(argc, argv); }
