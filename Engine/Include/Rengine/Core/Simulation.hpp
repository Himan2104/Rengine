#pragma once

#include"Rengine/Config.hpp"

namespace ren
{
    struct SimulationParams
    {

    };

    class REN_API Simulation final
    {
    public:
        Simulation();

        void Start();

        void Tick();

        void Stop();

        ~Simulation() noexcept = default;

    private:
        bool _isRunning = false;

    };
}
