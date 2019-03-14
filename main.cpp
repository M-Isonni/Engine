#include "Engine.h"
#include "Window.h"
#include "Renderer.h"
#include <stdio.h>

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