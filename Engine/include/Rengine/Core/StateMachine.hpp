#pragma once
#include<SFML/Graphics.hpp>
#include<stack>
#include<memory>
#include"Rengine/Core/State.hpp"
#include"Rengine/Config.hpp"


namespace ren
{
	class State;
	class Environment;
	
	class REN_API StateMachine : sf::NonCopyable
	{
	public:
		StateMachine();
		~StateMachine();

		void ChangeState(State* newState);
		State* GetActiveState();

	private:
		State* _current_state;
	};
}
