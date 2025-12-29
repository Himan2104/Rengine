#pragma once

namespace Ren::ECS
{

class ISystem
{
public:
    friend class World;
    ISystem()          = default;
    virtual ~ISystem() = default;

protected:
    virtual void Start()    = 0;
    virtual void Shutdown() = 0;
    virtual void Reset()    = 0;
    virtual void TickInternal();

    const World* GetWorld() const;
    World* GetWorld();

private:
    World* _world{nullptr};

    friend class World;
};

template <typename... Components>
class System : public ISystem
{
public:
    template <typename... Cs>
    class Query;

    System()          = default;
    virtual ~System() = default;

protected:
    virtual void Tick(Query<Components...> query) = 0;

private:
    void TickInternal() override { Tick(); }
};

} // namespace Ren::ECS
