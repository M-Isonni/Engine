#pragma once
#include "Actor.h"
#include "RenderComponent.h"


class Enemy : public engine::Actor {
public:
	Enemy();
	~Enemy();

protected:
	std::shared_ptr<engine::RenderComponent> RenderComponent;
	void Tick(float DeltaTime) override;
};
