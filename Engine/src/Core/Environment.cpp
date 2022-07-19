#include "Rengine/Core/Environment.hpp"
#include "Rengine/Core/AssetManager.hpp"
#include "Rengine/Core/StateMachine.hpp"

ren::Environment::Environment()
{
	assetManager = std::make_unique<AssetManager>();
	stateMachine = std::make_unique<StateMachine>();
}

ren::Environment::~Environment()
{
}

void ren::Environment::Dispose()
{
}
