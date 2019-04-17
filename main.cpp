#include "Engine.h"
#include "Window.h"
#include "Renderer.h"
#include <stdio.h>
#include "RenderComponent.h"
#include "Actor.h"
#include "Component.h"
#include "Context.h"
#include "GLProgram.h"
#include "Shader.h"

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

	engine::Window Window(800, 600);
	GameRenderer Renderer(Window);
	engine::Context Context(Window);
	
	engine::GLProgram Prg;	
	
	//ATTACCHING SHADERS -> to be put in a manager class
	engine::Shader vertex_shader(Vertex_Shader, "vertex.glsl");
	engine::Shader fragment_shader(Fragment_Shader, "frag.glsl");
	vertex_shader.AttachShader(Prg);
	fragment_shader.AttachShader(Prg);
	Prg.LinkProgram();
	vertex_shader.DetachShader(Prg);
	fragment_shader.DetachShader(Prg);
	fragment_shader.~Shader();
	vertex_shader.~Shader();
	Prg.UseProgram();
	//END ATTACHING SHADER	
	
	int running = 1;
	while (running)
	{
		Renderer.Clear();

		running = Window.DequeueEvent();

		Renderer.Tick();
		
		Renderer.Present();
	}	
	return 0;
}