#pragma once
#include<stdint.h>
#include<string>
#include<memory>

#include "Rengine/ECS/Entity.hpp"
#include "Rengine/ECS/System.hpp"


namespace ren::ecs
{
	class REN_API System;
	class REN_API Entity;

	class REN_API Component
	{
	public:
		Component(const std::string& identifier, std::shared_ptr<Entity> entity);
		virtual ~Component();

		uint_fast64_t getInstanceID();

		std::string getIdentifier();

		std::shared_ptr<Entity> getOwnerEntity();


	private:
		uint_fast64_t _instance_ID;		//instance of the entity it is attached to
		std::string _identifier;		//identifier of the component (RigidBody, ShapeRenderer, etc)
		std::shared_ptr<Entity> _entity; //owner entity/entity this component is attached to
		std::shared_ptr<System> _system; //System that handles this type of components

	};

}
