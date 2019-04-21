#include "Engine.h"
#include "Private.h"
#include "Shader.h"

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
	delete(Program);
	delete(Context);
	SDL_Quit();
}

void engine::Engine::Init(engine::Window& InWindow) {
	Context = new engine::Context(InWindow);
	Program = new engine::GLProgram();
}

void engine::Engine::compile_shader(ShaderType shader_type, const char* name) const
{
	engine::Shader shader(shader_type, name);	
	shader.AttachShader(*Program);
	Program->LinkProgram();
	shader.DetachShader(*Program);
}



