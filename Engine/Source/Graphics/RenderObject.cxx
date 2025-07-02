#include <Rengine/Graphics/RenderObject.hxx>

namespace Ren::Gfx
{

RenderObject::RenderObject(UInt32 id) { _id = id; }

void RenderObject::SetFlags(RenderFlags flags) { _renderFlags |= flags; }

void RenderObject::UnsetFlags(RenderFlags flags) { _renderFlags &= flags; }

bool RenderObject::HasFlags(RenderFlags flags) { return (_renderFlags & flags) == flags; }

} // namespace Ren::Gfx
