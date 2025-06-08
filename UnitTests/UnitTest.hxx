#pragma once

#include <format>
#include <string_view>
#include <vector>

namespace Ren::UT
{

enum class TestResult
{
    PASS,
    FAIL,
    WARNING,
    ABORTED
};

class Test
{
public:
    Test()          = default;
    virtual ~Test() = default;

    virtual std::string_view GetName() = 0;
    virtual TestResult Run()           = 0;
};

class TestRunner final
{
public:
    static TestRunner& GetInstance();

    template <typename T> void AddTest() { _tests.push_back(new T()); }
    void Start();

private:
    TestRunner()             = default;
    TestRunner(TestRunner&)  = delete;
    TestRunner(TestRunner&&) = delete;

    std::vector<Test*> _tests;
};

} // namespace Ren::UT

template <> struct std::formatter<Ren::UT::TestResult> : std::formatter<std::string_view>
{
    auto format(Ren::UT::TestResult logType, std::format_context& ctx) const
    {
        std::string_view name;
        switch (logType)
        {
        case Ren::UT::TestResult::PASS: name = "PASS"; break;
        case Ren::UT::TestResult::FAIL: name = "FAIL"; break;
        default: name = "UNKNOWN"; break;
        }
        return std::formatter<std::string_view>::format(name, ctx);
    }
};
