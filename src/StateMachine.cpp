#include "StateMachine.h"
#include "State.h"

StateMachine::StateMachine(engine::Actor& InOwner)
{
	states = std::vector<std::pair<E_State, State*>*>();
	current_state = NULL;
	owner = &InOwner;
}

//void StateMachine::Init() {
//	
//}

StateMachine::~StateMachine()
{
	delete(current_state);
	/*for (auto s : states) {
		delete(s);
	}*/
}

void StateMachine::RegisterState(std::pair<E_State, State*>* InState) {
	states.push_back(InState);
	InState->second->owner = std::make_shared<StateMachine>(*this);
}

engine::Actor& StateMachine::GetOwner()
{
	return *owner;
}

void StateMachine::ChangeState(E_State new_state) {
	if (current_state != NULL) {
		current_state->OnExitState();
	}
	for (auto s : states) {
		if (s->first==new_state) {
			current_state = s->second;
		}
	}
}

void StateMachine::Update() {
	current_state->Update();
}
