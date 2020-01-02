#include "MoveState.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "StateMachine.h"

MoveState::MoveState(StateMachine &InMachine) : State(InMachine)
{
}

MoveState::~MoveState()
{
}

void MoveState::Update(float DeltaTime)
{
	owner->owner->SetPosition(owner->owner->GetPosition() + direction * speed * DeltaTime);
	// std::cout << "updating move state" << std::endl;
}

void MoveState::OnExitState()
{
}
