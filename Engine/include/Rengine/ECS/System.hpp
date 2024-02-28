#pragma once
#include<stdint.h>
#include<string>
#include<vector>
#include"Rengine/ECS/Component.hpp"

namespace ren::ecs
{
	class REN_API Component;

	class REN_API System
	{
	public:
		System();
		virtual ~System();

		/// <summary>
		/// Manually set the tickrate of thee system.
		/// 0 -> tick every frame
		/// n -> tick n times per second (cannot exceed frame rate)
		/// </summary>
		/// <param name="tickRate"></param>
		void setTickRate(uint16_t tickRate);
		
		uint16_t getTickRate() const;
		
		virtual void update(float delTime) = 0;

	private:
		std::string _identifier;
		uint16_t _tick_rate;
		std::vector<std::shared_ptr<Component>> _components;
	};
}

