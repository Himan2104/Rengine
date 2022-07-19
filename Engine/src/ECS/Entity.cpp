#include "Rengine/ECS/Entity.hpp"
#include "Rengine/Utility/Debug.hpp"

ren::ecs::Entity::Entity(uint_fast64_t instanceID)
	:_instance_id(instanceID)
{
}

ren::ecs::Entity::~Entity()
{
	Debug::log("Entity " + std::to_string(_instance_id) + " destroyed.");
}

uint_fast64_t ren::ecs::Entity::getInstanceID()
{
	return _instance_id;
}

