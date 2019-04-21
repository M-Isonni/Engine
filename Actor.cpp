#include "Actor.h"
#include "World.h"

engine::Actor::Actor() {
		
}
engine::Actor::~Actor() {

}
void engine::Actor::InternalAddComponent(std::shared_ptr<engine::Component> Component) {
	this->Components.push_back(Component);
	
}

void engine::Actor::BeginPlay() {

}

void engine::Actor::Tick(float DeltaTime) {	
	for (auto Comp : Components) {
		Comp->Tick(DeltaTime);
	}
}