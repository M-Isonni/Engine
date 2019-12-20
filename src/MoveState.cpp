#include "MoveState.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "StateMachine.h"

MoveState::MoveState(StateMachine& InMachine) : State(InMachine)
{
}

MoveState::~MoveState()
{
}

void MoveState::Update()
{
	// owner->owner->GetComponent<engine::SpriteComponent>()->X += 0.01;
	// std::cout << "updating move state" << std::endl;
}

void MoveState::OnExitState()
{
}
