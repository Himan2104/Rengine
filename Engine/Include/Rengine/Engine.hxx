#pragma once

#include<Rengine/Core/IApplication.hxx>
#include<type_traits>
#include<concepts>
#include <utility>

namespace Ren
{
    template<typename T>
    concept IsApplication = std::is_base_of_v<IApplication, T>;

    class Engine
    {
    public:
        template<IsApplication T, typename... Args>
        static int StartApplication(Args &&... args)
        {
            if(_application)
            {
                return -1;
            }

            _application = new T(std::forward<Args>(args)...);
            return _application->Start();
        }

    private:
        static IApplication* _application;
    };
}
