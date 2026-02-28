#pragma once

#include "../../UnitTest.hxx"
#include "Rengine/Core/Vector.hxx"
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

        Vector2<Float16> vf1(1.5f16, 23.12f16), vf2(8.9f16, 1.4f16);
        auto vf3 = vf1 + vf2;
        return TestResult::PASS;
    }
};

} // namespace Ren::UT
