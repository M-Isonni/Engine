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

	//ATTACCHING SHADERS 
	
	std::vector<ShaderType> types;
	std::vector<const char*> names;

	types.push_back(Vertex_Shader);
	names.push_back("vertex.glsl");
	types.push_back(Fragment_Shader);
	names.push_back("frag.glsl");

	Engine.compile_shader(types, names);

	Engine.Program->UseProgram();
	//END ATTACHING SHADER	

	//Adding Actors
	std::shared_ptr<engine::Actor> Actor = std::make_shared<engine::Actor>();
	World.AddActor(Actor);
	std::shared_ptr<engine::Actor> Actor2 = std::make_shared<engine::Actor>();
	World.AddActor(Actor2);
	
	//Adding components to actor
	std::shared_ptr<engine::SpriteComponent> cmp = Actor->AddComponent<engine::SpriteComponent>();
	std::shared_ptr<engine::SpriteComponent> cmp2 = Actor2->AddComponent<engine::SpriteComponent>();
	
	int running = 1;
	Window.SetClearColor(0, 0, 0);

	unsigned int P = Engine.Program->GetProgram();	

	while (running)
	{
		//moving actors
		Actor->GetComponent<engine::SpriteComponent>()->X += 0.01;
		Actor->GetComponent<engine::SpriteComponent>()->Y += 0.01;
		Actor2->GetComponent<engine::SpriteComponent>()->X -= 0.01;
		Actor2->GetComponent<engine::SpriteComponent>()->Y += 0.01;

		Window.ClearWindow();
		running = Window.DequeueEvent();

		//component Ticks
		Manager.Tick(1/60);		

		SDL_GL_SwapWindow(reinterpret_cast<SDL_Window*>(Window.GetHandle()));
	}	
	return 0;
}