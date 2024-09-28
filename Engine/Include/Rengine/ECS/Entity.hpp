#pragma once
#include<stdint.h>
#include<string>
#include<vector>
#include<memory>

#include"Rengine/Config.hpp"
#include"Rengine/ECS/Component.hpp"

namespace ren::ecs
{
	class REN_API Component;

	class REN_API Entity
	{
	public:
		Entity();
		Entity(uint_fast64_t instanceID);
		~Entity();
		
		enum class State 
		{
			Active,		// Entity is active
			Inactive,	// Entity is inactive
			Destroyed	// Entity is destroyed (will free up memory when all references are destroyed)
		};

		std::string  identifier;

		uint_fast64_t getInstanceID();

	private:
		uint_fast64_t _instance_id;
		State _state;
		std::vector<std::shared_ptr<ren::ecs::Component>> _components;

		friend class EntityManager;
	};

}

