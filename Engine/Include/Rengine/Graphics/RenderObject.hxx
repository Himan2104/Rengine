#pragma once

#include <Rengine/Core/Definitions.hxx>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Vertex.hpp>

namespace Ren::Gfx
{

enum class RenderFlags : UInt8
{
    IsVisible     = 1 << 0,
    IsDynamic     = 1 << 1,
    IsBatched     = 1 << 2,
    IsParticle    = 1 << 3,
    PlaceHolder_4 = 1 << 4,
    PlaceHolder_5 = 1 << 5,
    PlaceHolder_6 = 1 << 6,
    PlaceHolder_7 = 1 << 7,

    IsStatic = !IsDynamic
};

class RenderObject final
{
public:
private:
    RenderObject() = delete;
    RenderObject(UInt32 id);
    void SetFlags(RenderFlags flags);
    bool HasFlags(RenderFlags flags);
    [[nodiscard]] RenderFlags& GetFlags();
    [[nodiscard]] RenderFlags GetFlags() const;

private:
    UInt32 _id;
    RenderFlags _renderFlags;
    sf::Vertex _vertices[4];
    sf::RenderStates _renderStates;

    friend class Renderer;
};

} // namespace Ren::Gfx
