#include "State.h"

State::State(StateMachine& InMachine)
{
	owner = std::make_shared<StateMachine>(InMachine);
}

State::~State()
{
}

void State::Update(float DeltaTime) {

}

void State::OnExitState() {

}
