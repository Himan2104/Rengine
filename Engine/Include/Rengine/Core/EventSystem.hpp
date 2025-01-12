#pragma once

#include<algorithm>
#include<concepts>
#include<map>
#include<memory>
#include<vector>
#include<typeindex>
#include<functional>
#include<pstl/glue_execution_defs.h>

namespace Ren
{
    class IEvent
    {
    public:
        virtual ~IEvent() = default;

    private:
        IEvent() = default;

        friend class EventSystem;
    };

    template<typename T>
    concept IsEvent = std::is_base_of<IEvent, T>::value;

    using Subscribers = std::vector<std::function<void *(IEvent &)>>;

    class EventSystem
    {
    public:
        static EventSystem &GetInstance();

        template<IsEvent T, typename... Args>
        void Invoke(Args &&... args)
        {
            T event(std::forward<Args>(args)...);
            auto& x = _subscribers[std::type_index(typeid(T))];
            std::for_each(std::execution::par, x.begin(), x.end(), [&](auto &e) { e(event); });
        }

        template<IsEvent T>
        void Subscribe(std::function<void *(T &)> callback)
        {
#ifdef REN_REPORT_EVENT_RESUBSCRIPTION

#endif
            _subscribers[std::type_index(typeid(T))].push_back(std::move(callback));

        }

    private:
        EventSystem() = default;

        std::map<std::type_index, Subscribers> _subscribers;
    };
}
