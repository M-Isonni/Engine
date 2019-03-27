#include "Component.h"
#include "Engine.h"


engine::Component::Component() {
	engine::Engine::Get().AddComponent(this);
}
void engine::Component::BeginPlay() {
	
}

void engine::Component::Tick(float DeltaTime) {

}