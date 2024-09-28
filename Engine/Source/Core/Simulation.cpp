#include"Rengine/Core/Simulation.hpp"

ren::Simulation::Simulation()
{

}

void ren::Simulation::Tick()
{
    if(!_isRunning)
    {
        return;
    }
}

void ren::Simulation::Start()
{
    _isRunning = true;
}

void ren::Simulation::Stop()
{
    _isRunning = false;
}
