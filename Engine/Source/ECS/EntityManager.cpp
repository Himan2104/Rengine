#include"Rengine/ECS/EnitityManager.hpp"

Ren::ecs::EntityManager::EntityManager()
{

}

Ren::ecs::EntityManager::~EntityManager()
{
}

std::shared_ptr<Ren::ecs::Entity> Ren::ecs::EntityManager::createEntity(const std::string& identifier)
{
	auto new_entity = std::make_shared<Ren::ecs::Entity>();
	if (_freeIDs.empty()) 
	{
		_entities.push_back(new_entity);
		new_entity->_instance_id = _entities.size() - 1;
	}
	else 
	{
		new_entity->_instance_id = _freeIDs.back();
		_freeIDs.pop_back();
		_entities[new_entity->_instance_id] = new_entity;
	}
	new_entity->identifier = identifier;
	return new_entity;
}

bool Ren::ecs::EntityManager::destroyEntity(uint_fast64_t instanceID)
{
	if (instanceID >= _entities.size())
		return false;
	_entities[instanceID]->_state = Ren::ecs::Entity::State::Destroyed;
	_entities[instanceID]->_instance_id = _freeIDs.back();
	_freeIDs.pop_back();
	_entities[instanceID] = nullptr;
	return true;
}

std::shared_ptr<Ren::ecs::Entity> Ren::ecs::EntityManager::getEntity(uint_fast64_t instanceID)
{
	return _entities[instanceID];
}

std::shared_ptr<Ren::ecs::Entity> Ren::ecs::EntityManager::getEntity(const std::string& identifier)
{
	return *std::find_if(_entities.begin(), _entities.end(), [&identifier](const std::shared_ptr<Ren::ecs::Entity>& entity) { return entity->identifier == identifier; });

	// Is this better?
	/*for (auto& entity : _entities)
	{
		if (entity->identifier == identifier)
			return entity;
	}
	return nullptr;*/
}

bool Ren::ecs::EntityManager::isValid(std::shared_ptr<Entity> entity) const
{
	return entity->_state == Entity::State::Active ? true : false;
}

bool Ren::ecs::EntityManager::isValid(uint_fast64_t instanceID) const
{
	return _entities[instanceID]->_state == Entity::State::Active ? true : false;
}

void Ren::ecs::EntityManager::clear()
{
	_entities.clear();
	_freeIDs.clear();
}

