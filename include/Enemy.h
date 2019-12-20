#pragma once
#include "Actor.h"
#include "SpriteComponent.h"
#include "StateMachine.h"
#include "MoveState.h"


class Enemy : public engine::Actor {
public:
	Enemy();
	~Enemy();
	std::shared_ptr<engine::SpriteComponent> Sprite;
	void SetPosition(float x, float y);
	void SetScale(float x, float y);	
	StateMachine* machine;
	MoveState* state;

protected:
	
	void Tick(float DeltaTime) override;
};
