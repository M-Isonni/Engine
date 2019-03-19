#include "Enemy.h"


Enemy::Enemy() {
	RenderComponent = AddComponent<engine::RenderComponent>();
	
}
Enemy::~Enemy() {


}

void Enemy::Tick(float DeltaTime) {

}