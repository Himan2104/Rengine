#include "Tests/Core/Math.hxx"
#include "UnitTest.hxx"

void RegisterTests() { Ren::UT::TestRunner::GetInstance().AddTest<Ren::UT::Vector2Test>(); }

int main()
{
    RegisterTests();
    Ren::UT::TestRunner::GetInstance().Start();
    return 0;
}
