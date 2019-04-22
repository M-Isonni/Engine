#include "Enemy.h"
#include "World.h"


Enemy::Enemy() : engine::Actor::Actor() {	
	Sprite = this->AddComponent<engine::SpriteComponent>();
	std::cout <<"INComp" << this->Components.size() << std::endl;	
}
Enemy::~Enemy() {	

}

void Enemy::Tick(float DeltaTime) {
	Actor::Tick(DeltaTime);
	Sprite->X += 0.1 * DeltaTime;
}

void Enemy::SetPosition(float x, float y) {
	Sprite->Init(x, y);
}

void Enemy::SetScale(float x, float y) {
	Sprite->SetScale(x, y);
}