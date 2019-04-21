#include "Engine.h"
#include "Window.h"
#include <stdio.h>
#include "Actor.h"
#include "SpriteComponent.h"
#include "World.h"
#include "GameManager.h"


int main(int argc, char **argv) {

	engine::Engine& Engine= engine::Engine::Get();
	engine::World& World = engine::World::Get();	
	engine::GameManager& Manager= engine::GameManager::Get();
		
	Engine.RegisterComponent<engine::SpriteComponent>();

	engine::Window Window(800, 600);
	
	//setting up context and program
	Engine.Init(Window);

	//ATTACCHING SHADERS -> to be put in a manager class

	Engine.compile_shader(Vertex_Shader, "vertex.glsl");
	Engine.compile_shader(Fragment_Shader, "frag.glsl");

	Engine.Program->UseProgram();
	//END ATTACHING SHADER	

	//Adding Actors
	std::shared_ptr<engine::Actor> Actor = std::make_shared<engine::Actor>();
	World.AddActor(Actor);
	//engine::World::Get().Actors.push_back(Actor);
	//

	//Adding components to actor
	std::shared_ptr<engine::SpriteComponent> cmp = Actor->AddComponent<engine::SpriteComponent>();
	
	int running = 1;
	while (running)
	{
		Engine.ClearWindow();
		running = Window.DequeueEvent();		
		Manager.Tick(1/60);	
		std::shared_ptr<engine::Actor> A = World.Actors[0];		
	}	
	return 0;
}