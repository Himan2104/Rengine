#pragma once

#include <Rengine/Core/Types.hxx>
#include <Rengine/Graphics/RenderFlags.hxx>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Vertex.hpp>

namespace Ren::Gfx
{

class RenderObject final
{
public:
private:
    RenderObject() = delete;
    RenderObject(UInt32 id);

    void SetFlags(RenderFlags flags);
    void UnsetFlags(RenderFlags flags);
    [[nodiscard]] bool HasFlags(RenderFlags flags);

    [[nodiscard]] RenderFlags& GetFlags() { return _renderFlags; }
    [[nodiscard]] RenderFlags GetFlags() const { return _renderFlags; }

private:
    UInt32 _id;
    RenderFlags _renderFlags{RenderFlags::Default};
    sf::Vertex _vertices[4];
    sf::RenderStates _renderStates;

    friend class Renderer;
};

} // namespace Ren::Gfx
