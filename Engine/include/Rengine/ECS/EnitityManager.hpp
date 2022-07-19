#pragma once
#include<memory>
#include<algorithm>
#include"Rengine/ECS/Entity.hpp"

namespace ren::ecs
{
	class EntityManager
	{
	public:
		EntityManager();
		~EntityManager();

		/// <summary>
		/// Creates and returns a new entity.
		/// </summary>
		/// <param name="identifier">Human readable call-sign</param>
		/// <returns>shared pointer to a new blank entity</returns>
		std::shared_ptr<Entity> createEntity(const std::string& identifier = "NewEntity");
		
		/// <summary>
		/// Queue an entity for destruction.
		/// </summary>
		/// <param name="instanceID">instance ID of the entity</param>
		/// <returns>true if deleted. false if entity does not exist (maybe deleted already?)</returns>
		bool destroyEntity(uint_fast64_t instanceID);
		
		/// <summary>
		/// Get an entity by its instance ID.
		/// </summary>
		/// <param name="instanceID">instance ID of the entity</param>
		/// <returns>Queried entity</returns>
		std::shared_ptr<Entity> getEntity(uint_fast64_t instanceID);
		std::shared_ptr<Entity> getEntity(const std::string& identifier);

		/// <summary>
		/// return if an entity is active or not.
		/// </summary>
		/// <returns></returns>
		bool isValid(std::shared_ptr<Entity> entity) const;
		bool isValid(uint_fast64_t instanceID) const;

		void clear();
		
	private:
		std::vector<std::shared_ptr<Entity>> _entities;
		std::vector<uint_fast64_t> _freeIDs;
	};
}