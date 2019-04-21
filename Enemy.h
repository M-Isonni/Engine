#pragma once
#include "Actor.h"


class Enemy : public engine::Actor {
public:
	Enemy();
	~Enemy();

protected:
	
	void Tick(float DeltaTime) override;
};
