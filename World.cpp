#include "World.h"

engine::World::World() {
		
}

engine::World& engine::World::Get() {
	static World* Singleton = nullptr;
	if (!Singleton) {
		Singleton = new World();
	}
	return *Singleton;
}
engine::World::~World() {
	
}

void engine::World::AddActor(std::shared_ptr<engine::Actor> InActor) {
	Actors.push_back(InActor);
}