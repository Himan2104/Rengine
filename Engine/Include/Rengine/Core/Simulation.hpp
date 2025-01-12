#pragma once

#include"Rengine/Config.hpp"

namespace Ren
{
    struct SimulationParams
    {

    };

    class Simulation
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
