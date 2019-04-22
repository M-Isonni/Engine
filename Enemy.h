#pragma once
#include "Actor.h"
#include "SpriteComponent.h"


class Enemy : public engine::Actor {
public:
	Enemy();
	~Enemy();
	std::shared_ptr<engine::SpriteComponent> Sprite;
	void SetPosition(float x, float y);
	void SetScale(float x, float y);

protected:
	
	void Tick(float DeltaTime) override;
};
