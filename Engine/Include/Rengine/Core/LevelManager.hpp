#pragma once
#include <Rengine/Config.hpp>
#include <Rengine/Core/Level.hpp>
#include <concepts>
#include <memory>
#include <stack>

namespace Ren
{
class Application;
class Level;

template <typename T>
concept IsLevel = std::is_base_of<Level, T>::value;

class LevelManager final
{
public:
    explicit LevelManager(Application* application);

    template <IsLevel T, typename... Args> void LoadLevel(Args&&... args);

    [[nodiscard]] Level* GetActiveLevel() const { return _currentLevel.get(); }

    template <IsLevel T> [[nodiscard]] T* GetActiveLevel() const { return static_cast<T*>(_currentLevel.get()); }

private:
    std::unique_ptr<Level> _currentLevel;
};

#include <Rengine/Core/LevelManager.inl>

} // namespace Ren
