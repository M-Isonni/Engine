#pragma once
#include "State.h"

class MoveState : public State {
public:
	MoveState(StateMachine& InMachine);
	virtual ~MoveState();
	virtual void Update() override;
	virtual void OnExitState() override;
};