#pragma once

#include"Rengine/Config.hpp"
#include<memory>

namespace ren
{
	class REN_API StateMachine;
	class REN_API AssetManager;
	
	class REN_API Environment
	{
	public:
		Environment();
		~Environment();

		std::shared_ptr<AssetManager> GetAssetManager() const
		{
			return _asset_manager;
		}

		std::shared_ptr<StateMachine> GetStateMachine() const
		{
			return _state_machine;
		}

		void Dispose();

	private:
		Environment(const Environment&) = delete;
		Environment& operator=(const Environment&) = delete;

		std::shared_ptr<AssetManager> _asset_manager;
		std::shared_ptr<StateMachine> _state_machine;

	};
}

