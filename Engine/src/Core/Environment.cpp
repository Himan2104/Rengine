#include "Rengine/Core/Environment.hpp"
#include "Rengine/Core/AssetManager.hpp"
#include "Rengine/Core/StateMachine.hpp"

ren::Environment::Environment()
{
	_asset_manager = std::make_shared<AssetManager>();
	_state_machine = std::make_shared<StateMachine>();
}

ren::Environment::~Environment()
{
}

void ren::Environment::Dispose()
{
}
