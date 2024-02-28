#include"Rengine/core/StateMachine.hpp"
#include<iostream>

ren::StateMachine::StateMachine():
	_current_state(nullptr)
{
}

ren::StateMachine::~StateMachine()
{
}

void ren::StateMachine::ChangeState(ren::State* newState)
{
	State* temp = _current_state;
	_current_state = newState;
	_current_state->Initialize();
	delete[] temp;
}

ren::State* ren::StateMachine::GetActiveState()
{
	return _current_state;
}
