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

		void changeState(State* newState);
		State* getActiveState();

	private:
		State* _current_state;
	};
}
