#include "Rengine/Application/Resolution.hxx"
#include "Rengine/Core/EventSystem.hxx"
#include "Rengine/Core/Log.hxx"
#include "Rengine/Core/Types.hxx"
#include "Rengine/Core/Vector.hxx"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/WindowEnums.hpp"
#include <Rengine/Application/Window.hxx>
#include <SFML/Window/Window.hpp>
#include <imgui-SFML.h>
#include <optional>

#define __REN_HANDLE_WINDOW_EVENT_ALIAS__(EventName, AliasName) \
    if (event->is<sf::Event::EventName>()) Ren::EventSystem::GetInstance().Invoke<WindowEvents::AliasName>();

#define __REN_HANDLE_WINDOW_EVENT_NO_ALIAS__(EventName) __REN_HANDLE_WINDOW_EVENT_ALIAS__(EventName, EventName)

#define __REN_GET_MACRO__(_1, _2, NAME, ...) NAME
#define REN_HANDLE_WINDOW_EVENT(...) \
    __REN_GET_MACRO__(__VA_ARGS__, __REN_HANDLE_WINDOW_EVENT_ALIAS__, __REN_HANDLE_WINDOW_EVENT_NO_ALIAS__)(__VA_ARGS__)

namespace Ren
{
class WindowImpl final
{
public:
    WindowImpl(Resolution resolution, UInt8 colorDepth, const std::string& title, WindowMode windowMode)
        : _resolution(resolution)
        , _colorDepth(colorDepth)
        , _title(title)
        , _windowMode(windowMode)
    {
        sf::VideoMode videoMode;
        if (_windowMode == WindowMode::Fullscreen)
        {
            videoMode = sf::VideoMode(Vector2u32(_resolution.GetWidth(), _resolution.GetHeight()), _colorDepth);
            if (!videoMode.isValid()) videoMode = sf::VideoMode::getDesktopMode();
        }
        else
            videoMode = sf::VideoMode(Vector2u32(_resolution.GetWidth(), _resolution.GetHeight()), _colorDepth);

        _window = new sf::RenderWindow(videoMode, title, sf::Style::Default);

        if (!ImGui::SFML::Init(*_window)) REN_LOG_ERROR("IMGUI subsystem could not be initialized!");
    }

    void PollEvents()
    {
        while (std::optional event = _window->pollEvent())
        {
            ImGui::SFML::ProcessEvent(*_window, event.value());
            REN_HANDLE_WINDOW_EVENT(Closed);
            REN_HANDLE_WINDOW_EVENT(Resized);
            REN_HANDLE_WINDOW_EVENT(FocusLost);
            REN_HANDLE_WINDOW_EVENT(FocusGained);
            REN_HANDLE_WINDOW_EVENT(TextEntered);
            REN_HANDLE_WINDOW_EVENT(KeyPressed);
            REN_HANDLE_WINDOW_EVENT(KeyReleased);
            REN_HANDLE_WINDOW_EVENT(MouseWheelScrolled);
            REN_HANDLE_WINDOW_EVENT(MouseButtonPressed);
            REN_HANDLE_WINDOW_EVENT(MouseButtonReleased);
            REN_HANDLE_WINDOW_EVENT(MouseMoved);
            REN_HANDLE_WINDOW_EVENT(MouseEntered);
            REN_HANDLE_WINDOW_EVENT(MouseLeft, MouseExited);

            // TODO: Implement remaining events
        }

        ImGui::SFML::Update(*_window, _deltaClock.restart());
    }

    void Close()
    {
        ImGui::SFML::Shutdown(*_window);
        _window->close();
        delete _window;
        _window = nullptr;
    }

    void SetResolution(Resolution resolution) { _resolution = resolution; }
    Resolution GetResolution() const { return _resolution; }
    void SetColorDepth(UInt8 colorDepth) { _colorDepth = colorDepth; }
    UInt8 GetColorDepth() const { return _colorDepth; }
    void SetTitle(const std::string& title) { _title = title; }
    const std::string& GetTitle() const { return _title; }
    void SetWindowMode(WindowMode windowMode) { _windowMode = windowMode; }
    WindowMode GetWindowMode() const { return _windowMode; }
    void Clear(Color clearColor) { _window->clear(sf::Color(clearColor.ToUInt32())); }
    void Display()
    {
        ImGui::SFML::Render(*_window);
        _window->display();
    }

private:
    sf::RenderWindow* _window{nullptr};

    Resolution _resolution;
    UInt8 _colorDepth;
    std::string _title;
    WindowMode _windowMode;
    sf::Clock _deltaClock;
};

Window::Window(Resolution resolution, UInt8 colorDepth, const std::string& title, WindowMode windowMode)
    : _windowImpl{new WindowImpl(resolution, colorDepth, title, windowMode)}
{
}

void Window::PollEvents() { _windowImpl->PollEvents(); }

void Window::Close()
{
    _windowImpl->Close();
    delete _windowImpl;
    // TODO: cleanup
}

void Window::SetResolution(Resolution resolution) { _windowImpl->SetResolution(resolution); }
Resolution Window::GetResolution() const { return _windowImpl->GetResolution(); }
void Window::SetColorDepth(UInt8 colorDepth) { _windowImpl->SetColorDepth(colorDepth); }
UInt8 Window::GetColorDepth() const { return _windowImpl->GetColorDepth(); }
void Window::SetTitle(const std::string& title) { _windowImpl->SetTitle(title); }
const std::string& Window::GetTitle() const { return _windowImpl->GetTitle(); }
void Window::SetWindowMode(WindowMode windowMode) { _windowImpl->SetWindowMode(windowMode); }
WindowMode Window::GetWindowMode() const { return _windowImpl->GetWindowMode(); }
void Window::Clear(Color clearColor) { _windowImpl->Clear(clearColor); }
void Window::Display() { _windowImpl->Display(); }

} // namespace Ren
