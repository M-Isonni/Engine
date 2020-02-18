#pragma once
#include "Enemy.h"
#include "World.h"
#include "PhysicsMgr.h"


Enemy::Enemy() 
{
	
}
Enemy::~Enemy() 
{	
	delete(machine);
	delete(state);
}

void Enemy::Tick(float DeltaTime)
{	
	Actor::Tick(DeltaTime);
	machine->Update(DeltaTime);	
}

void Enemy::BeginPlay()
{
	BoxCollider = this->AddComponent<engine::BoxCollider>(this);
	Sprite = this->AddComponent<engine::SpriteComponent>(this);
	BoxCollider->OnCollision.AddListener(&Enemy::OnCollision);
	engine::PhysicsMgr::Get().AddCollider(BoxCollider);
	machine = new StateMachine(*this); 
	state = new MoveState(*machine);
	std::pair<E_State, State*>* pair = new std::pair<E_State, State*>(IDLE, state);
	machine->RegisterState(pair);
	machine->current_state = machine->states[0]->second;	
	Actor::BeginPlay();
}

void Enemy::OnCollision(const engine::Actor* owner, std::shared_ptr<engine::Collider> other_collider)
{
	std::cout<<"Collision from actor: "<<owner->ID<<"\n";
}

