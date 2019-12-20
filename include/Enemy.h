#pragma once
#include "Actor.h"
#include "SpriteComponent.h"
#include "StateMachine.h"
#include "MoveState.h"
#include "BoxCollider.h"


class Enemy : public engine::Actor {
public:
	Enemy();
	~Enemy();
	std::shared_ptr<engine::SpriteComponent> Sprite;
	std::shared_ptr<engine::BoxCollider> BoxCollider;		
	StateMachine* machine;
	MoveState* state;
	

protected:
	
	void Tick(float DeltaTime) override;
	void BeginPlay() override;
};
