#pragma once
#include <vector>
#include <map>

enum E_State { IDLE, PATROL, CHASE };
class State;
class Actor;
class StateMachine {
public:
	StateMachine();
	~StateMachine();
	StateMachine(StateMachine& InMachine) = delete;
	Actor* owner;
	
	State* current_state;
	std::vector<std::map<E_State, State>*> states;

	void Update();
	void Init(Actor& InOwner);
	void ChangeState(E_State new_state);
	void RegisterState(std::map<E_State, State>& InState);
};
