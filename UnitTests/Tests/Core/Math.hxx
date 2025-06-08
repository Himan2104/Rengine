#pragma once

#include "../../UnitTest.hxx"
#include "Rengine/Core/Math/Vector2.hxx"
#include <string_view>

namespace Ren::UT
{

class Vector2Test : public Test
{
    std::string_view GetName() override { return "Vector2 Test"; }

    TestResult Run() override
    {
        Vector2u32 vec1(4, 5), vec2(5, 4);
        auto vec3 = vec1 + vec2;
        return TestResult::PASS;
    }
};

} // namespace Ren::UT
