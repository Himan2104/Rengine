#include "Rengine/ECS/System.hpp"

Ren::ecs::System::System():
	_identifier("unknown_system"),
	_tick_rate(0)
{
}

Ren::ecs::System::~System()
{
}

void Ren::ecs::System::setTickRate(uint16_t tickRate)
{
	_tick_rate = tickRate;
}

uint16_t Ren::ecs::System::getTickRate() const
{
	return _tick_rate;
}
