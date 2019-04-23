#pragma once
#include <memory>
#include "StateMachine.h"



//only to be used to inherit and create new states for state machine
//cannot make abstract cause type is needed as general as function argument
class State
{
public:
	State(StateMachine& owning_machine);
	virtual ~State();
	virtual void Update();
	virtual void OnExitState();
	std::shared_ptr<StateMachine> owner;
protected:
};
