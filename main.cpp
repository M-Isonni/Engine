#include "Engine.h"
#include "Window.h"
#include "Renderer.h"
#include <stdio.h>
#include "Actor.h"
#include "Component.h"
#include "Context.h"
#include "GLProgram.h"
#include "Shader.h"
#include "SpriteComponent.h"
#include "World.h"
#include "GameManager.h"


int main(int argc, char **argv) {

	engine::Engine& Engine= engine::Engine::Get();
	engine::World& World = engine::World::Get();	
	//engine::GameManager& Manager= engine::GameManager::Get();
		
	Engine.RegisterComponent<engine::SpriteComponent>();

	engine::Window Window(800, 600);
	

	//creating context for openGL
	engine::Context Context(Window);
	
	engine::GLProgram Prg;	
	
	//Manager.Init(Window);

	//ATTACCHING SHADERS -> to be put in a manager class

	/*Manager.compile_shader(Vertex_Shader, "vertex.glsl");
	Manager.compile_shader(Fragment_Shader, "frag.glsl");*/

	engine::Shader vertex_shader(Vertex_Shader, "vertex.glsl");
	engine::Shader fragment_shader(Fragment_Shader, "frag.glsl");
	vertex_shader.AttachShader(Prg);
	fragment_shader.AttachShader(Prg);
	Prg.LinkProgram();
	vertex_shader.DetachShader(Prg);
	fragment_shader.DetachShader(Prg);	

	Prg.UseProgram();

	//Manager.Program.UseProgram();
	//END ATTACHING SHADER	
	
	int running = 1;
	while (running)
	{
		//Manager.ClearWindow();
		running = Window.DequeueEvent();		
		//Manager.Tick(1/60);	
		
	}	
	return 0;
}