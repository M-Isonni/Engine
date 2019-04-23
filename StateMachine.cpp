#include "StateMachine.h"
#include "State.h"

StateMachine::StateMachine()
{
	states = std::vector<std::map<E_State, State>*>();
	current_state = NULL;
}

void StateMachine::Init(Actor& InOwner) {
	owner = &InOwner;
}

StateMachine::~StateMachine()
{
}

void StateMachine::RegisterState(std::map<E_State, State>& InState) {
	states.push_back(&InState);
}

void StateMachine::ChangeState(E_State new_state) {
	if (current_state != NULL) {
		current_state->OnExitState();
	}
	for (auto s : states) {
		if (s->count(new_state)) {
			current_state = &s->at(new_state);
		}
	}
}

void StateMachine::Update() {
	current_state->Update();
}
