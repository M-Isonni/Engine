#include "Engine.h"
#include "Private.h"

engine::Engine::Engine() {
	Context = nullptr;
	Program = nullptr;
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

void engine::Engine::compile_shader(std::vector<ShaderType> shader_types,std::vector<const char*> names) const
{
	std::vector<engine::Shader> shaders;
	for (int i = 0; i < shader_types.size();i++) {		
		engine::Shader shader(shader_types[i], names[i]);		
		shaders.push_back(shader);
		shader.AttachShader(*Program);
	}	

	Program->LinkProgram();

	for (int i = 0; i < shader_types.size();i++) {
		shaders[i].DetachShader(*Program);
	}		
}



