#include "Engine.h"
#include "Window.h"
#include <stdio.h>
#include "Actor.h"
#include "SpriteComponent.h"
#include "World.h"
#include "GameManager.h"
#include "Enemy.h"
#include "event.h"
#include "PhysicsMgr.h"

int main(int argc, char **argv) {

	engine::Engine& Engine= engine::Engine::Get();
	engine::World& World = engine::World::Get();	
	engine::GameManager& Manager= engine::GameManager::Get();
	engine::PhysicsMgr& PhysicsMgr= engine::PhysicsMgr::Get();
		
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
	std::shared_ptr<Enemy> e2 = World.AddActor<Enemy>();

	int running = 1;
	Window.SetClearColor(0, 0, 0);

	unsigned int P = Engine.Program->GetProgram();	
	float delta_time = 1.0f / 60.0f;
	Manager.BeginPlay();

	//Modifies to Actor behaviours need to occur after manager begin play is called
	e->ID=1;
	e2->ID=2;

	e->Sprite->SetColor(1, 0, 1, 1);
	e2->Sprite->SetColor(0, 1, 0, 1);

	e->SetDirection(Vector3(1,0,0));
	e->SetSpeed(10);

	e->SetPosition(100,100,0);
	e->SetScale(2,2,1);

	e2->SetDirection(Vector3(0,-1,0));
	e2->SetSpeed(10);

	e2->SetPosition(400,300,0);
	e2->SetScale(2,2,1);

	std::cout <<"Actors " << World.Actors.size() << std::endl;
	
	while (running)
	{
	// 	for (int i = 0; i < World.Actors.size(); i++) 
	// {
	// 	//std::cout << "Actor " << World.Actors[i]->ID<<" components: "<<World.Actors[i]->get_components_num() << std::endl;
	// 	std::cout<< "Actor: "<<World.Actors[i]->ID<< " scale: "<<World.Actors[i]->GetComponent<engine::SpriteComponent>()->transform->scale.X<<", "
	// 	<<World.Actors[i]->GetComponent<engine::SpriteComponent>()->transform->scale.Y<<".\n";
	// }
		Window.ClearWindow();
		running = Window.DequeueEvent();
		PhysicsMgr.Tick(delta_time);
		//Actor Tick - Component Tick
		Manager.Tick(delta_time);

		SDL_GL_SwapWindow(reinterpret_cast<SDL_Window*>(Window.GetHandle()));
	}	
	return 0;
}