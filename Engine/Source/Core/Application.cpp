#include <typeinfo>
#include <Rengine/Core/Application.hpp>
#include <Rengine/Core/LevelManager.hpp>
#include <Rengine/Core/AssetManager.hpp>
#include <utility>

ren::Application::Application(ren::ApplicationProperties app_properties):
    _properties(std::move(app_properties))
{
    _window.create(_properties.settings.video_mode,
        _properties.name + " v" + _properties.GetVersionString(),
        _properties.settings.fullscreen ? sf::Style::Fullscreen : sf::Style::Close);

    _window.setVerticalSyncEnabled(_properties.settings.vsync);

    if(!_properties.settings.vsync)
    {
        _window.setFramerateLimit(_properties.settings.framerate_limit);
    }

    _font.loadFromFile("C:/Windows/Fonts/consola.ttf");
    _debugText.setFont(_font);
    _debugText.setCharacterSize(21);
    _debugText.setPosition(10.0f, 10.0f);
    _debugText.setFillColor(sf::Color::White);
}


ren::Application::~Application()
{
}

void ren::Application::Run(Level* firstState)
{
    _environment->GetStateMachine()->LoadLevel<TestState>();
    TimeKeeper::InitializeTime();

    while (_isRunning)
    {
        TimeKeeper::UpdateTime();

        sf::Event event{};
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) _isRunning = false;
            _environment->GetStateMachine()->GetActiveLevel()->EventHandler(event, _window);
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Tilde)
                    ren::Debug::log("OpenConsole");
        }

        _environment->GetStateMachine()->GetActiveLevel()->Update(TimeKeeper::DeltaTime());

        _window.clear();
        _environment->GetStateMachine()->GetActiveLevel()->Render(_window);
        _debugText.setString(
                "FPS: " + std::to_string(1.0f / TimeKeeper::DeltaTime()) + "\n" +
                "FrameTime: " + std::to_string(TimeKeeper::DeltaTime() * 1000.0f) + " ms \n" +
                "True Clock: " + std::to_string(TimeKeeper::TimeSinceStart(TimeKeeper::ClockType::Static)) + " s\n" +
                "Scaled Clock: " + std::to_string(TimeKeeper::TimeSinceStart(TimeKeeper::ClockType::Dynamic)) + " s\n" +
                "Level: " + typeid(*_environment->GetStateMachine()->GetActiveLevel()).name()
                );
        _window.draw(_debugText);
        _window.display();
    }

    CloseApplication();
}

void ren::Application::CloseApplication(int exitCode)
{
    _window.close();
    std::exit(exitCode);
}
