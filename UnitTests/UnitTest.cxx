#include "UnitTest.hxx"
#include <format>
#include <iostream>

namespace Ren::UT
{

TestRunner& TestRunner::GetInstance()
{
    static TestRunner t;
    return t;
}

void TestRunner::Start()
{
    unsigned int testCount = _tests.size();

    std::cout << std::format("Starting {} unit tests...\n", testCount);

    unsigned int completedTestCount = 0;
    unsigned int completionPercent  = 0;

    unsigned int passedTests = 0;

    for (auto test : _tests)
    {
        std::cout << std::format("[{}] Running Test {} ....... ", completionPercent, test->GetName());

        auto result = test->Run();

        completedTestCount++;

        if (result == TestResult::PASS)
        {
            passedTests++;
            std::cout << "PASS\n";
        }
        else { std::cout << "FAIL\n"; }

        completionPercent = ((float)completedTestCount / (float)testCount) * 100;
    }

    std::cout << std::format("{}/{} passed ({})", passedTests, testCount, (passedTests / testCount) * 100);
}

} // namespace Ren::UT
