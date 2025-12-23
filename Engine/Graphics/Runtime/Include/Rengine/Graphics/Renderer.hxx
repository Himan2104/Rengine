#pragma once

#include <Rengine/Core/Array.hxx>
#include <Rengine/Core/Types.hxx>
#include <Rengine/Core/UIDProvider.hxx>
#include <Rengine/Graphics/RenderObject.hxx>

namespace Ren::Gfx
{

class Renderer
{
public:
    using Batch = DynamicArray<RenderObject>;

    Renderer() = default;

    RenderObject* CreateRenderObject();

private:
    std::vector<RenderObject> _renderObjects;
    UIDProvider<UInt32> _uidProvider;
    DynamicArray<sf::Texture> _textureBank;
};

} // namespace Ren::Gfx
