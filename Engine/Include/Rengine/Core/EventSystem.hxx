#pragma once

#include "Rengine/Core/UIDProvider.hxx"
#include <Rengine/Config.hxx>
#include <Rengine/Core/Array.hxx>
#include <Rengine/Core/Definitions.hxx>
#include <Rengine/Core/Hash.hxx>
#include <Rengine/Core/Log.hxx>
#include <algorithm>
#include <functional>
#include <map>
#include <memory>
#include <utility>

namespace Ren
{

using EventSubscriptionToken = UInt32;

class IEvent // Interface for all Events
{
};

template <typename T>
concept IsEvent = std::is_base_of<IEvent, T>::value;

class EventSystem
{
public:
    using EventTypeID            = UInt64;
    using EventSubscriptionToken = UInt32;
    using TCallback              = std::function<void(std::shared_ptr<IEvent>)>;
    using SubscriberEntry        = std::pair<EventSubscriptionToken, TCallback>;
    using Subscribers            = DynamicArray<SubscriberEntry>;

    static EventSystem& GetInstance();

    template <IsEvent T, typename... Args>
    void Invoke(Args&&... args);
    template <IsEvent T>
    EventSubscriptionToken Subscribe(TCallback callback);
    template <IsEvent T>
    void Unsubscribe(EventSubscriptionToken est);

private:
    EventSystem() = default;

    template <IsEvent T>
    consteval static EventTypeID GetEventTypeID()
    {
        return Hashing::FNV1A(REN_FUNC_SIG);
    }

private:
    std::map<EventTypeID, Subscribers> _subscribers;
    UIDProvider<EventSubscriptionToken> _uidProvider;
};

template <IsEvent T, typename... Args>
void EventSystem::Invoke(Args&&... args)
{
    auto event = std::make_shared<T>(T{{}, std::forward<Args>(args)...});
    auto& x    = _subscribers[GetEventTypeID<T>()];
    std::for_each(x.Begin(), x.End(), [&](auto& pair) { pair.second(event); });
}

template <IsEvent T>
EventSubscriptionToken EventSystem::Subscribe(TCallback callback)
{
    EventSubscriptionToken e = _uidProvider.GetNewUID();
    _subscribers[GetEventTypeID<T>()].PushBack(std::move(std::make_pair(e, callback)));
    return e;
}

template <IsEvent T>
void EventSystem::Unsubscribe(EventSubscriptionToken est)
{
    auto& x = _subscribers[GetEventTypeID<T>()];
    auto it = std::find_if(x.Begin(), x.End(), [&](const auto& entry) { return entry.first == est; });
    if (it != x.End())
    {
        x.Remove(it);
        _uidProvider.FreeID(est);
        return;
    }

#ifdef REN_EVSYS_LOG_FAILED_UNSUBSCRIBE
    REN_LOG_WARNING("EventSubscriptionToken Not Found! It has probably already been deleted.")
#endif
}

} // namespace Ren
