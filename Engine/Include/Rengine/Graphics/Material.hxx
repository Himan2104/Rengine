#pragma once

#include "SFML/Graphics/Shader.hpp"
#include "SFML/Graphics/Texture.hpp"
namespace Ren::Gfx
{

class Material final
{
    const sf::Texture* _texture;
    sf::Shader _shader;
};

} // namespace Ren::Gfx
