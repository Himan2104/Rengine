//LevelManager inline template defs

template<IsLevel T, typename... Args>
inline void LevelManager::LoadLevel(Args &&... args)
{
    _currentLevel = std::make_unique<T>(std::forward<Args>(args)...);
}
