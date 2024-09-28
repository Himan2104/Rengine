#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <Rengine/Config.hpp>

namespace ren
{
    class Application;
    class LevelManager;

    class Level
    {
    public:
        Level() = default;
        virtual ~Level() = default;
        virtual void Initialize() = 0;
        virtual void EventHandler(sf::Event& event, const sf::RenderWindow& window) = 0;
        virtual void Update(float delTime) = 0;
        virtual void Render(sf::RenderTarget& target) = 0;

    protected:
        [[nodiscard]] std::shared_ptr<Application> GetApplication() const { return _application.lock(); }

        [[nodiscard]] std::shared_ptr<LevelManager> GetLevelManager() const { return _levelManager.lock(); }

    private:
        void InternalTick(float deltaTime);

    private:
        std::weak_ptr<Application> _application;
        std::weak_ptr<LevelManager> _levelManager;

        friend class LevelManager;
    };
}