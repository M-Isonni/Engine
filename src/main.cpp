#include "Engine.h"
#include "Window.h"
#include <stdio.h>
#include "Actor.h"
#include "SpriteComponent.h"
#include "World.h"
#include "GameManager.h"
#include "Enemy.h"
#include "event.h"

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
	names.push_back("shaders/vertex.glsl");
	types.push_back(Fragment_Shader);
	names.push_back("shaders/frag.glsl");

	Engine.compile_shader(types, names);

	Engine.Program->UseProgram();
	//END ATTACHING SHADER	

	//in order to create Actors Create them throught the world
	std::shared_ptr<Enemy> e = World.AddActor<Enemy>();	
	e->Sprite->SetColor(1, 0, 1, 1);

	std::shared_ptr<Enemy> e2 = World.AddActor<Enemy>();	
	e2->Sprite->SetColor(0, 1, 0, 1);

	std::cout <<"Actors " << World.Actors.size() << std::endl;
	for (int i = 0; i < World.Actors.size(); i++) {
		std::cout << "components " << World.Actors[i]->GetComponents<engine::SpriteComponent>().size() << std::endl;
	//std::cout<<"e comp "	<<e.GetComponents<engine::SpriteComponent>().size() << std::endl;
	}
	
	int running = 1;
	Window.SetClearColor(0, 0, 0);

	unsigned int P = Engine.Program->GetProgram();	
	float delta_time = 1.0f / 60.0f;
	Manager.BeginPlay();
	e->SetPosition(100,100,0);
	e->SetScale(2,2,1);
	while (running)
	{
		
		Window.ClearWindow();
		running = Window.DequeueEvent();

		//Actor Tick - Component Tick
		Manager.Tick(delta_time);

		SDL_GL_SwapWindow(reinterpret_cast<SDL_Window*>(Window.GetHandle()));
	}	
	return 0;
}