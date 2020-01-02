#pragma once
#include "Actor.h"
#include "SpriteComponent.h"
#include "StateMachine.h"
#include "MoveState.h"
#include "BoxCollider.h"

class Enemy : public engine::Actor
{
public:
	Enemy();
	~Enemy();
	std::shared_ptr<engine::SpriteComponent> Sprite;
	std::shared_ptr<engine::BoxCollider> BoxCollider;
	StateMachine *machine;
	MoveState *state;
	inline void SetDirection(Vector3 in_dir){state->Direction(in_dir);};
	inline void SetSpeed(float in_speed){state->Speed(in_speed);};

private:
	static void OnCollision(const engine::Actor* owner, std::shared_ptr<engine::Collider> other_collider);

protected:
	void Tick(float DeltaTime) override;
	void BeginPlay() override;
};
