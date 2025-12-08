#include "Rengine/ECS/Component.hxx"


Ren::ecs::Component::Component(const std::string& identifier, std::shared_ptr<Entity> entity)
	:_identifier(identifier), _entity(entity), _instance_ID(entity->getInstanceID())
{

}

Ren::ecs::Component::~Component()
{
}

uint_fast64_t Ren::ecs::Component::getInstanceID()
{
	return _instance_ID;
}

std::string Ren::ecs::Component::getIdentifier()
{
	return _identifier;
}

std::shared_ptr<Ren::ecs::Entity> Ren::ecs::Component::getOwnerEntity()
{
	return _entity;
}

