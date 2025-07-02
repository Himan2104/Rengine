#include "Tests/Core/Array.hxx"
#include "Tests/Core/Math.hxx"
#include "UnitTest.hxx"

void RegisterTests()
{
    Ren::UT::TestRunner::GetInstance().AddTest<Ren::UT::Vector2Test>();
    Ren::UT::TestRunner::GetInstance().AddTest<Ren::UT::ArrayTest>();
}

int main()
{
    RegisterTests();
    Ren::UT::TestRunner::GetInstance().Start();
    return 0;
}
