#include"Rengine/core/StateMachine.hpp"
#include<iostream>

ren::StateMachine::StateMachine()
{
	current_state = nullptr;
}

ren::StateMachine::~StateMachine()
{
}

ren::StateMachine* ren::StateMachine::access()
{
	static StateMachine SM;
	return &SM;
}

void ren::StateMachine::changeState(State* newState)
{
	State* temp = current_state;
	current_state = newState;
	current_state->initialize();
	delete[] temp;
}

State* &ren::StateMachine::getActiveState()
{
	return current_state;
}
