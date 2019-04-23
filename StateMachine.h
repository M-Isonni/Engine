#pragma once
#include <vector>
#include <map>
#include "Actor.h"

enum E_State { IDLE, PATROL, CHASE };
class State;
class Actor;
class StateMachine {
public:
	StateMachine(engine::Actor& InOwner);
	~StateMachine();
	
	engine::Actor* owner;	
	State* current_state;
	std::vector<std::pair<E_State, State*>*> states;
	void Update();
	//void Init(Actor& InOwner);
	void ChangeState(E_State new_state);
	void RegisterState(std::pair<E_State, State*>* InState);

	engine::Actor& GetOwner();
};
