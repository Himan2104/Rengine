#pragma once

#include <Rengine/Application/Resolution.hxx>
#include <Rengine/Core/Color.hxx>
#include <Rengine/Core/Types.hxx>
#include <Rengine/Core/EventSystem.hxx>
#include <Rengine/Core/Math/Vector2.hxx>
#include <string>

namespace Ren
{
enum class WindowMode : UInt8
{
    Windowed   = 0,
    Fullscreen = 1
};

class Window final
{
public:
    Window(Resolution resolution, UInt8 colorDepth, const std::string& title, WindowMode windowMode);

    void PollEvents();
    [[nodiscard]] bool IsOpen() const;
    void Close();
    void SetResolution(Resolution resolution);
    [[nodiscard]] Resolution GetResolution() const;
    void SetColorDepth(UInt8 colorDepth);
    [[nodiscard]] UInt8 GetColorDepth() const;
    void SetTitle(const std::string& title);
    [[nodiscard]] const std::string& GetTitle() const;
    void SetWindowMode(WindowMode windowMode);
    [[nodiscard]] WindowMode GetWindowMode() const;
    void Clear(Color clearColor = Color::Black);
    void Display();

private:
    class WindowImpl* _windowImpl = nullptr;
};

namespace WindowEvents
{
    // Window closed [Alt+F4 or X]
    struct Closed : IEvent
    {
    };

    // Window bounds resized
    struct Resized : IEvent
    {
        Vector2u32 newSize;
    };

    // Window lost focus
    struct FocusLost : IEvent
    {
    };

    // Window gained focus
    struct FocusGained : IEvent
    {
    };

    // Text Entered while in focus [Gives unicode. For keys check KeyPressed and KeyReleased]
    struct TextEntered : IEvent
    {
        char32_t unicode;
    };

    // Key pressed down [Gives keycode. For unicode/text usage see TextEntered]
    struct KeyPressed : IEvent
    {
        // TODO: Custom keyboard implementation
        // Key + Scancode
    };

    // Key released [Gives keycode. For unicode/text usage see TextEntered]
    struct KeyReleased : IEvent
    {
        // TODO: Custom keyboard implementation
        // Key + Scancode
    };

    struct MouseWheelScrolled : IEvent
    {
        Float32 delta;
    };
    struct MouseButtonPressed : IEvent
    {
        UInt8 buttonState;
        Vector2i32 position;
    };
    struct MouseButtonReleased : IEvent
    {
        UInt8 buttonState;
        Vector2i32 position;
    };
    struct MouseMoved : IEvent
    {
        Vector2i32 position;
    };
    struct MouseMovedRaw : IEvent
    {
        Vector2i32 delta;
    };
    struct MouseEntered : IEvent
    {
    };
    struct MouseExited : IEvent
    {
    };

    // TODO: Implement remaining Event Types from SFML's window events

} // namespace WindowEvents

} // namespace Ren
