#pragma once
#include<SFML/Graphics.hpp>
#include<stack>
#include<memory>
#include"Rengine/core/State.hpp"
#include"Rengine/Config.hpp"


namespace ren
{
	class REN_API StateMachine : sf::NonCopyable
	{
	public:
		StateMachine();
		~StateMachine();

		static StateMachine* access();

		void changeState(State* newState);
		State*& getActiveState();

	private:
		State* current_state;
	};
}
