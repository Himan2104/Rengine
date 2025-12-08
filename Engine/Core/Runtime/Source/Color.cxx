#include <Rengine/Core/Color.hxx>

namespace Ren
{

constexpr Color::Color(UInt8 r, UInt8 g, UInt8 b, UInt8 a = 255)
    : r{r}
    , g{g}
    , b{b}
    , a{a}
{
}

constexpr Color::Color(UInt32 color)
    : r(static_cast<UInt8>((color & 0xff'00'00'00) >> 24))
    , g(static_cast<UInt8>((color & 0xff'00'00'00) >> 16))
    , b(static_cast<UInt8>((color & 0xff'00'00'00) >> 8))
    , a(static_cast<UInt8>((color & 0xff'00'00'00) >> 0))
{
}

constexpr Color Color::Zero(0, 0, 0, 0);
constexpr Color Color::Black(0, 0, 0);
constexpr Color Color::White(255, 255, 255);
constexpr Color Color::Red(255, 0, 0, 0);
constexpr Color Color::Blue(0, 0, 255);
constexpr Color Color::Green(0, 255, 0);
constexpr Color Color::Cyan(0, 255, 255);
constexpr Color Color::Yellow(255, 255, 0);
constexpr Color Color::Magenta(255, 0, 255);

} // namespace Ren
