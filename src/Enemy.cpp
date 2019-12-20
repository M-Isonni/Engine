#pragma once
#include "Enemy.h"
#include "World.h"


Enemy::Enemy() : engine::Actor::Actor() {	
	Sprite = this->AddComponent<engine::SpriteComponent>();
	BoxCollider = this->AddComponent<engine::BoxCollider>();
	std::cout <<"INComp" << this->Components.size() << std::endl;	
	machine = new StateMachine(*this);
	state = new MoveState(*machine);
	std::pair<E_State, State*>* pair = new std::pair<E_State, State*>(IDLE, state);
	machine->RegisterState(pair);
	machine->current_state = machine->states[0]->second;
}
Enemy::~Enemy() {	
	delete(machine);
	delete(state);
}

void Enemy::Tick(float DeltaTime) {
	Actor::Tick(DeltaTime);
	machine->Update();	
}

void Enemy::BeginPlay()
{
	Actor::BeginPlay();
	SetPosition(0,0,0);
	SetScale(1,1,1);
}

