#include "Rengine/core/State.hpp"

ren::State::State(std::weak_ptr<ren::Environment> environment)
{
	this->_global_env = environment;
}