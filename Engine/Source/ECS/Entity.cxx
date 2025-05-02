#include "Rengine/ECS/Entity.hxx"
#include "Rengine/Utility/Debug.hxx"

Ren::ecs::Entity::Entity()
	: _instance_id(0), _state(State::Active)
{
}

Ren::ecs::Entity::Entity(uint_fast64_t instanceID)
	:_instance_id(instanceID), _state(State::Active)
{
}

Ren::ecs::Entity::~Entity()
{
	Debug::log("Entity " + std::to_string(_instance_id) + " destroyed.");
}

uint_fast64_t Ren::ecs::Entity::getInstanceID()
{
	return _instance_id;
}

