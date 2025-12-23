#include "Rengine/Core/Types.hxx"
#include <Rengine/Graphics/RenderObject.hxx>
#include <Rengine/Graphics/Renderer.hxx>

namespace Ren::Gfx
{

RenderObject* Renderer::CreateRenderObject()
{
    UInt32 newId = _uidProvider.GetNewUID();
    _renderObjects.push_back(RenderObject(newId));
    return &_renderObjects.back();
}

} // namespace Ren::Gfx
