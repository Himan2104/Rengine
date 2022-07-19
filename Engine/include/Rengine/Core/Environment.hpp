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

		std::unique_ptr<AssetManager> assetManager;
		std::unique_ptr<StateMachine> stateMachine;

		void Dispose();

	private:
		Environment(const Environment&);
		Environment& operator=(const Environment&);

	};
}

