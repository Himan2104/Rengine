#include "Rengine/ECS/System.hpp"

constexpr ren::ecs::System::System():
	_identifier("unknown_system"),
	_tick_rate(0)
{
}

ren::ecs::System::~System()
{
}

void ren::ecs::System::setTickRate(uint16_t tickRate)
{
	_tick_rate = tickRate;
}

uint16_t ren::ecs::System::getTickRate() const
{
	return _tick_rate;
}
