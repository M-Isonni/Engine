#include "Enemy.h"
#include "World.h"


Enemy::Enemy() : engine::Actor::Actor() {	
	Sprite = this->AddComponent<engine::SpriteComponent>();
	std::cout <<"INComp" << this->Components.size() << std::endl;	
	machine = new StateMachine(*this);
	state = new MoveState(*machine);
	std::pair<E_State, State*>* pair = new std::pair<E_State, State*>(IDLE, state);
	machine->RegisterState(pair);
	machine->current_state = machine->states[0]->second;
}
Enemy::~Enemy() {	

}

void Enemy::Tick(float DeltaTime) {
	Actor::Tick(DeltaTime);
	machine->Update();
	//Sprite->X += 0.1 * DeltaTime;
}

void Enemy::SetPosition(float x, float y) {
	Sprite->Init(x, y);
}

void Enemy::SetScale(float x, float y) {
	Sprite->SetScale(x, y);
}