#pragma once

#include "../../UnitTest.hxx"
#include "Rengine/Core/Definitions.hxx"
#include <Rengine/Core/Array.hxx>
#include <string_view>

namespace Ren::UT
{

class ArrayTest : public Test
{
    std::string_view GetName() override { return "Array Test"; }

    TestResult Run() override
    {
        DynamicArray<UInt32> nums;

        for (UInt32 i = 1; i <= 50; i++) { nums.PushBack(i); }

        UInt32 res = 0;
        for (auto num : nums) { res += num; }

        return res == 1275 ? TestResult::PASS : TestResult::FAIL;
    }
};

} // namespace Ren::UT
