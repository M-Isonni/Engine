#pragma once


//only to be used to inherit and create new states for state machine
//cannot make abstract cause type is needed as general as function argument
class State
{
public:
	State();
	virtual ~State();
	virtual void Update();
	virtual void OnExitState();
};
