#pragma once
#include <stack>
#include <memory>
#include <concepts>
#include <SFML/System/NonCopyable.hpp>
#include <Rengine/Core/Level.hpp>
#include <Rengine/Config.hpp>

namespace Ren
{
    class Application;
    class Level;

    template<typename T>
    concept IsLevel = std::is_base_of<Level, T>::value;

    class LevelManager final : sf::NonCopyable
    {
    public:
        explicit LevelManager(Application* application);

        template<IsLevel T, typename... Args>
        void LoadLevel(Args &&... args);

        [[nodiscard]] Level* GetActiveLevel() const { return _currentLevel.get(); }

        template<IsLevel T>
        [[nodiscard]] T* GetActiveLevel() const { return static_cast<T*>(_currentLevel.get()); }

    private:
        std::unique_ptr<Level> _currentLevel;
    };

#include<Rengine/Core/LevelManager.inl>

}