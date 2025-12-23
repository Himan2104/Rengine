#pragma once

#include <Rengine/Core/Types.hxx>

namespace Ren::Gfx
{

enum class RenderFlags : UInt8
{
    None = 0,

    Visible       = 1 << 0,
    Dynamic       = 1 << 1,
    CanBatch      = 1 << 2,
    Batched       = 1 << 3,
    Particle      = 1 << 4,
    PlaceHolder_5 = 1 << 5,
    PlaceHolder_6 = 1 << 6,
    PlaceHolder_7 = 1 << 7,

    Default = Visible | Dynamic | CanBatch
};

constexpr RenderFlags operator|(RenderFlags lhs, RenderFlags rhs)
{
    return static_cast<RenderFlags>(static_cast<UInt8>(lhs) | static_cast<UInt8>(rhs));
}

constexpr RenderFlags operator&(RenderFlags lhs, RenderFlags rhs)
{
    return static_cast<RenderFlags>(static_cast<UInt8>(lhs) & static_cast<UInt8>(rhs));
}

constexpr RenderFlags& operator|=(RenderFlags& lhs, RenderFlags rhs)
{
    lhs = lhs | rhs;
    return lhs;
}

constexpr RenderFlags& operator&=(RenderFlags& lhs, RenderFlags rhs)
{
    lhs = lhs & rhs;
    return lhs;
}

constexpr RenderFlags operator~(RenderFlags flag) { return static_cast<RenderFlags>(~static_cast<UInt8>(flag)); }

} // namespace Ren::Gfx
