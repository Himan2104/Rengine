#include"Rengine/Core/Simulation.hpp"

namespace Ren
{
Simulation::Simulation()
{

}

void Simulation::Tick()
{
    if(!_isRunning)
    {
        return;
    }
}

void Simulation::Start()
{
    _isRunning = true;
}

void Simulation::Stop()
{
    _isRunning = false;
}
}