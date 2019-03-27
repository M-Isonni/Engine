#include "Engine.h"
#include "Private.h"

engine::Engine::Engine() {
	
	SDL_Init(SDL_INIT_VIDEO);
	ComponentCounter = 0;
}

engine::Engine& engine::Engine::Get() {
	static Engine* Singleton = nullptr;
	if (!Singleton) {
		Singleton = new Engine();
	}

	return *Singleton;
}
engine::Engine::~Engine() {
	SDL_Quit();
}

void engine::Engine::AddComponent(engine::Component* comp) {
	engine::Component& ref = *comp;
	Components.push_back(ref);
	free(comp);
}
void engine::Engine::InitComponents() {
	for (auto i = Components.begin; i < Components.end; i++)
	{
		Components[i].BeginPlay();
	}	
}
void engine::Engine::UpdateComponents(float deltaTime) {
	for (auto i = Components.begin; i < Components.end; i++)
	{
		Components[i].Tick();
	}
}

