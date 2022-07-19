#include "Rengine/ECS/Component.hpp"


ren::ecs::Component::Component(const std::string& identifier, std::shared_ptr<Entity> entity)
	:_identifier(identifier), _entity(entity), _instance_ID(entity->getInstanceID())
{

}

ren::ecs::Component::~Component()
{
}

uint_fast64_t ren::ecs::Component::getInstanceID()
{
	return _instance_ID;
}

std::string ren::ecs::Component::getIdentifier()
{
	return _identifier;
}

std::shared_ptr<ren::ecs::Entity> ren::ecs::Component::getOwnerEntity()
{
	return _entity;
}

