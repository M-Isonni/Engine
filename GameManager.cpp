#include "GameManager.h"
#include "World.h"
#include "Actor.h"
#include "Private.h"
#include "Shader.h"
#include "Context.h"

engine::GameManager::GameManager()
{
}

engine::GameManager & engine::GameManager::Get()
{
	static GameManager* Singleton = nullptr;
	if (!Singleton) {
		Singleton = new GameManager();
	}

	return *Singleton;
}

engine::GameManager::~GameManager()
{
}

void engine::GameManager::Tick(float DeltaTime) {
	for (engine::Actor a : engine::World::Get().Actors) {		
		a.Tick(DeltaTime);
	}
}

void engine::GameManager::ClearWindow()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void engine::GameManager::Init(engine::Window& InWindow) {
	engine::Context Context(InWindow);
	engine::GLProgram Prg;
	Program = Prg;
}

void engine::GameManager::compile_shader(ShaderType shader_type, const char * name)
{
	engine::Shader shader(shader_type, name);
	//engine::Shader fragment_shader(Fragment_Shader, "frag.glsl");
	shader.AttachShader(Program);
	//fragment_shader.AttachShader(Prg);
	Program.LinkProgram();
	shader.DetachShader(Program);
	//fragment_shader.DetachShader(Prg);
	
}
