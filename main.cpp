#include "Engine.h"
#include "Window.h"
#include "Renderer.h"
#include <stdio.h>
#include "RenderComponent.h"
#include "Actor.h"
#include "Component.h"

class GameRenderer :public engine::Renderer {
public:
	GameRenderer(engine::Window& InWindow) : engine::Renderer(InWindow) {}
	void Tick() override;
};

void GameRenderer::Tick() {
	DrawLine(100, 100, 200, 200);
}

int main(int argc, char **argv) {

	engine::Engine& Engine= engine::Engine::Get();

	Engine.RegisterComponent<engine::RenderComponent>();

	engine::Actor actor = engine::Actor();	
	actor.AddComponent<engine::RenderComponent>();
	std::shared_ptr<engine::RenderComponent> RenderComponent = actor.GetComponent<engine::RenderComponent>();
	printf("%d", RenderComponent->ComponentType);

	std::vector<std::shared_ptr<engine::RenderComponent>> renderComponents = actor.GetComponents<engine::RenderComponent>();
	printf("%d", renderComponents[0]->Type);

	engine::Window Window(800, 600);
	GameRenderer Renderer(Window);

	for (;;)
	{
		Renderer.Clear();

		Window.DequeueEvent();
		Renderer.Tick();
		
		Renderer.Present();
	}	
	return 0;
}