#include"Rengine/core/StateMachine.hpp"
#include<iostream>

ren::StateMachine::StateMachine()
{
	currentState = nullptr;
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
	State* temp = currentState;
	currentState = newState;
	currentState->initialize();
	delete[] temp;
}

State* &ren::StateMachine::getActiveState()
{
	return currentState;
}
