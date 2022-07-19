#include"Rengine/core/StateMachine.hpp"
#include<iostream>

ren::StateMachine::StateMachine():
	_current_state(nullptr)
{
}

ren::StateMachine::~StateMachine()
{
}

void ren::StateMachine::changeState(ren::State* newState)
{
	State* temp = _current_state;
	_current_state = newState;
	_current_state->initialize();
	delete[] temp;
}

ren::State* ren::StateMachine::getActiveState()
{
	return _current_state;
}
