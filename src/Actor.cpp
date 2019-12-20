#pragma once
#include "Actor.h"
#include "World.h"


void engine::Actor::InternalAddComponent(std::shared_ptr<engine::Component> Component) {
	this->Components.push_back(Component);
	
}



void engine::Actor::Tick(float DeltaTime) {	
	for (auto Comp : Components) {
		Comp->Tick(DeltaTime);
	}
}